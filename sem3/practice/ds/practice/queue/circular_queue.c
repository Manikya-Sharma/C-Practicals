// circular queue

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 10

struct queue {
    int front;
    int rear;
    int items[MAX_QUEUE];
};

int empty_stack(struct queue *pq)
{
    if (pq->rear == pq->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *pq, int item)
{
    if (pq->rear == MAX_QUEUE - 1) {
        if (pq->front == 0) {
            printf("Overflow!\n");
            exit(1);
        }
        pq->rear = 0;
        pq->items[MAX_QUEUE-1] = item;
    }
    else {
        if (pq->rear == pq->front - 1) {
            printf("Overflow!\n");
            exit(1);
        }
        pq->items[pq->rear++] = item;
    }
}

int remove_q(struct queue *pq)
{
    if (pq->front == MAX_QUEUE - 1) {
        int item = pq->items[pq->front];
        pq->front = 0;
        return item;
    }
    else {
        return pq->items[pq->front++];
    }
}

void print_queue(struct queue *pq)
{
    if (pq->front < pq->rear) {
        for (int i = pq->front; i < pq->rear; i++) {
            printf("%d ", pq->items[i]);
        }
        printf("\n");
    }
    else {
        for (int i = pq->front; i < MAX_QUEUE ; i++) {
            printf("%d ", pq->items[i]);
        }
        for (int i = 0; i < pq->rear; i++) {
            printf("%d ", pq->items[i]);
        }
        printf("\n");
    }
}


int main()
{
    struct queue q;
    q.rear = q.front = MAX_QUEUE-1;

    insert(&q, 1);
    insert(&q, 5);
    insert(&q, 7);

    print_queue(&q);

    remove_q(&q);

    print_queue(&q);
    return 0;
}