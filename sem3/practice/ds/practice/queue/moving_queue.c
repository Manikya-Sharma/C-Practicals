// queue with modified remove to avoid absurd situation

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 100

struct queue {
    int rear;
    int items[MAX_QUEUE];
};

int empty(struct queue *pq)
{
    if (pq->rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *pq, int item)
{
    if (pq->rear == MAX_QUEUE - 1) {
        printf("Overflow!\n");
        exit(1);
    }
    pq->items[++pq->rear] = item;
}

int remove_q(struct queue *pq)
{
    if (empty(pq)) {
        printf("Underlfow!\n");
        exit(1);
    }
    int elem = pq->items[0];
    for (int i = 1; i <= pq->rear; i++) {
        pq->items[i - 1] = pq->items[i];
    }
    pq->rear--;
    return elem;
}

void display_queue(struct queue *pq)
{
    for (int i = 0; i <= pq->rear; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.rear = -1;

    insert(&q, 1);
    insert(&q, 5);
    insert(&q, 7);

    display_queue(&q);

    remove_q(&q);

    display_queue(&q);
    return 0;
}