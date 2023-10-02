// circular priority queue

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
    if (pq->front == pq->rear) {
        return 1;
    }
    else {
        return 0;
    }
}

int full(struct queue *pq)
{
    if ((pq->rear == pq->front - 1) ||
        (pq->front == 0 && pq->rear == MAX_QUEUE - 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *pq, int item)
{
    if (full(pq)) {
        printf("Overflow!\n");
        exit(1);
    }
    if (pq->rear == MAX_QUEUE - 1) {
        pq->items[MAX_QUEUE - 1] = item;
        pq->rear = 0;
    }
    else {
        pq->items[pq->rear++] = item;
    }
}

int remove_q(struct queue *pq)
{
    if (pq->front < pq->rear) {
        int min_idx = pq->front;
        for (int i = pq->front; i < pq->rear; i++) {
            if (pq->items[i] < pq->items[min_idx]) {
                min_idx = i;
            }
        }
        int item = pq->items[min_idx];
        for (int j = min_idx; j < pq->rear - 1; j++) {
            pq->items[j] = pq->items[j + 1];
        }
        pq->rear--;
        return item;
    }
    else {
        int min_idx = 0;
        for (int i = 0; i < pq->rear; i++) {
            if (pq->items[i] < pq->items[min_idx]) {
                min_idx = i;
            }
        }
        for (int i = pq->front; i < MAX_QUEUE; i++) {
            if (pq->items[i] < pq->items[min_idx]) {
                min_idx = i;
            }
        }
        int item = pq->items[min_idx];
        int changeBeggining = 0;

        for (int j = min_idx; j < MAX_QUEUE; j++) {
            if (j == MAX_QUEUE - 1) {
                pq->items[MAX_QUEUE - 1] = pq->items[0];
                changeBeggining = 1;
            }
            pq->items[j] = pq->items[j + 1];
        }

        if (changeBeggining) {
            for (int j = 0; j < pq->rear - 1; j++) {
                pq->items[j] = pq->items[j + 1];
            }
        }
        if (pq->rear == 0) {
            pq->rear = MAX_QUEUE - 1;
        }
        else {
            pq->rear--;
        }
        return item;
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
        for (int i = pq->front; i < MAX_QUEUE; i++) {
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
    q.rear = q.front = MAX_QUEUE - 1;

    insert(&q, 1);
    insert(&q, 5);
    insert(&q, 7);

    print_queue(&q);

    remove_q(&q);

    print_queue(&q);
    return 0;
}