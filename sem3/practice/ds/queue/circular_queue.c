#include <stdio.h>
#define MAXQUEUE 100

struct priority_queue {
    int front, rear;
    int items[MAXQUEUE];
};

int empty(struct priority_queue *pq)
{
    if (pq->front == pq->rear) {
        return 1;
    }
    else {
        return 0;
    }
}

int full(struct priority_queue *pq)
{
    if (pq->rear == pq->front - 1 ||
        (pq->rear == MAXQUEUE - 1 && pq->front == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct priority_queue *pq, int elem)
{
    if (full(pq)) {
        printf("Queue full!");
        return;
    }
    if (pq->rear == MAXQUEUE - 1) {
        pq->rear = 0;
        pq->items[MAXQUEUE - 1] = elem;
        return;
    }
    pq->items[pq->rear++] = elem;
}

int remove_q(struct priority_queue *pq)
{
    if (empty(pq)) {
        printf("Undeflow!");
        return 0;
    }
    if (pq->front == MAXQUEUE - 1) {
        pq->front = 0;
        return pq->items[MAXQUEUE - 1];
    }
    return pq->items[pq->front++];
}

int main()
{
    struct priority_queue q;
    q.front = q.rear = MAXQUEUE - 1;

    int stop_execution = 0;
    printf("Enter operation:\n");
    printf("1. Enter element\n");
    printf("2. Remove element\n");
    printf("3. Print queue\n");
    printf("4. Quit\n");
    char input;
    int elem;
    while (!stop_execution) {
        printf("> ");
        scanf("%c", &input);
        switch (input) {
        case '1':
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(&q, elem);
            break;
        case '2':
            elem = remove_q(&q);
            printf("Removed %d", elem);
            break;
        case '3':
            // print_q(&q);
            break;
        case '4':
            printf("Thank you\n");
            stop_execution = 1;
        }
    }

    return 0;
}