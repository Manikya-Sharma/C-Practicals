#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

struct stack {
    int top;
    int items[STACK_SIZE];
};

struct queue {
    struct stack data;
    struct stack auxiliary;
};

int empty(struct queue *pq)
{
    if (pq->data.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *pq, int item)
{
    if (pq->data.top == STACK_SIZE - 1) {
        printf("Overflow!\n");
        exit(1);
    }
    // push to stack
    pq->data.items[++pq->data.top] = item;
}

int remove_q(struct queue *pq)
{
    while (pq->data.top != -1) {
        // pop from data and push to auxiliary
        pq->auxiliary.items[++pq->auxiliary.top] =
            pq->data.items[pq->data.top--];
    }
    // pop from auxiliary
    int item = pq->auxiliary.items[pq->auxiliary.top--];
    // pop form auxiliary and push to data
    while (pq->auxiliary.top != -1) {
        // pop from data and push to auxiliary
        pq->data.items[++pq->data.top] =
            pq->auxiliary.items[pq->auxiliary.top--];
    }
    return item;
}

void display(struct queue *pq)
{
    for (int i = 0; i <= pq->data.top; i++) {
        printf("%d ", pq->data.items[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.data.top = -1;
    q.auxiliary.top = -1;

    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    insert(&q, 4);

    display(&q);

    remove_q(&q);

    display(&q);

    return 0;
}