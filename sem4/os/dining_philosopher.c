#include<stdio.h>

typedef int semaphore;

void signal(semaphore* s) {
    (*s)++;
}

int wait(semaphore*s) {
    if (*s <= 0) {
        printf("Waiting on spin-loop\n");
        return 0;
    }
    (*s)--;
    return 1;
}

semaphore chopstick[5] = {1, 1, 1, 1, 1};

void show_menu();

void dine(int i) {
    if (!wait(&chopstick[i])) {
        printf("Chopstick %d not available, enter spin-lock\n", i);
        return;
    }
    if (!wait(&chopstick[(i+1)%5])) {
        printf("Chopstick %d not available, enter spin-lock\n", (i+1)%5);
        // in real implementation, signal is not needed because there will be spin-lock
        signal(&chopstick[i]);
        return;
    }
    printf("Philosopher %d is eating\n", i);
    show_menu();
    printf("Philosopher %d finished eating\n", i);
    signal(&chopstick[i]);
    signal(&chopstick[(i+1)%5]);
}

void show_menu() {
    int option;
    do {
        printf("1. Make a philosopher eat\n");
        printf("0. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 0:
                break;
            case 1: {
                int philosopher;
                printf("Enter the philosopher number: ");
                scanf("%d", &philosopher);
                dine(philosopher);
                break;
            }
            default:
                printf("Invalid option\n");
        }
    } while (option != 0);
}

int main() {
    show_menu();
    return 0;
}
