// linear queue

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100

struct queue {
    int front;
    int rear;
    int items[MAX_QUEUE];
};

int empty(struct queue *pq)
{
    if (pq->rear < pq->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *pq, int elem)
{
    if (pq->rear == MAX_QUEUE - 1) {
        printf("Overflow!\n");
        exit(1);
    }
    pq->items[++pq->rear] = elem;
}

int remove_q(struct queue *pq)
{
    if (pq->front == MAX_QUEUE - 1) {
        printf("Underlfow!\n");
        exit(1);
    }
    return pq->items[pq->front++];
}

void display_queue(struct queue *pq)
{
    for (int i = pq->front; i <= pq->rear; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.front = 0;
    q.rear = -1;

    insert(&q, 1);
    insert(&q, 5);
    insert(&q, 7);

    display_queue(&q);

    remove_q(&q);

    display_queue(&q);
    return 0;
}