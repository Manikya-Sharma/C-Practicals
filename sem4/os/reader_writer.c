#include <stdio.h>

typedef int semaphore;
void signal(semaphore* s) {
    (*s)++;
}
int wait(semaphore* s) {
    if (*s <= 0) {
        printf("Semaphore waiting in spin lock\n");
        return 0;
    }
    (*s)--;
    return 1;
}

// mutex which avoids race in reading and writing
semaphore rw_mutex = 1;
// mutex which avoids race in changing read_count
semaphore mutex = 1;
int read_count = 0;

// forward declaration
void show_menu();

void writer() {
    if (!wait(&rw_mutex))
        return;

    printf("Writer has entered its critical section\n");
    printf("Enter operation to be performed during its operation\n");

    show_menu();

    printf("Writer has left its critical section\n");
    signal(&rw_mutex);
}

void reader() {
    if (!wait(&mutex)) {
        printf("Read mutex cannot be acquired\n");
        return;
    }
    read_count++;
    if (read_count == 1) {
        if (!wait(&rw_mutex)) {
            // release the read mutex so that it can be accessed later
            // although in a real implementation this will not return and
            // intead will be in a spin-lock
            signal(&mutex);
            read_count--;
            return;
        }
    }
    signal(&mutex);

    printf("Reader %d has entered its critical section\n", read_count);
    printf("Enter operation to be performed during its operation\n");
    show_menu();

    printf("Reader %d has left its critical section\n", read_count);
    if (!wait(&mutex))
        return;
    read_count--;
    if (read_count == 0)
        signal(&rw_mutex);
    signal(&mutex);
}

void show_menu() {
    int option;
    do {
        printf("0. Exit\n");
        printf("1. Write\n");
        printf("2. Read\n");
        scanf("%d", &option);
        switch (option) {
            case 0:
                break;
            case 1:
                writer();
                break;
            case 2:
                reader();
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 0);
}

int main() {
    printf("No thread is working, enter your operation\n");
    show_menu();
    return 0;
}
