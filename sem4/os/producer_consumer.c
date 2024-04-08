#include <stdio.h>
#define BUFFER_SIZE 10

typedef struct {
} item;

// the common buffer managed by producer and consumer
item buffer[BUFFER_SIZE];
// the pointer which gives location after which producer will produce
int in = 0;
// the pointer at which the consumer will read
int out = 0;

void produce() {
    if (((in + 1) % BUFFER_SIZE) == out) {
        printf(
            "The buffer is full, there is busy wait till consumer consumes\n");
        return;
    }
    in = (in + 1) % BUFFER_SIZE;
}

void consume() {
    if (in == out) {
        printf(
            "The buffer is empty, there is a busy wait till producer "
            "produces\n");
        return;
    }
    // consume the item
    out = (out + 1) % BUFFER_SIZE;
}

int main() {
    int choice;
    do {
        printf("1. Produce an item\n");
        printf("2. Consume an item\n");
        printf("0. Quit\n");
        scanf("%d", &choice);
        // in an OS, the threads run in an infinite loop, asking either to produce or to consume
        switch (choice) {
            case 0:
                break;
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            default:
                printf("Invalid operation\n");
        }
    } while (choice != 0);
    return 0;
}
