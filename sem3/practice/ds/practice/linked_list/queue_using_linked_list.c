#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

typedef struct Node *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }

void freeNode(NODEPTR node) { free(node); }

struct queue {
    NODEPTR front;
    NODEPTR rear;
};

int empty(struct queue *pq)
{
    if (pq->rear->next == pq->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *pq, int info)
{
    NODEPTR node = getNode();
    node->info = info;
    node->next = pq->rear->next;
    pq->rear->next = node;
}

int remove_q(struct queue *pq)
{
    if (empty(pq)) {
        printf("Underflow!\n");
        exit(1);
    }
    NODEPTR temp = pq->rear;
    while (temp->next->next != pq->front) {
        temp = temp->next;
    }
    NODEPTR removeNode = temp->next;
    temp->next = temp->next->next;
    int info = removeNode->info;
    freeNode(removeNode);
    return info;
}

void display_queue(struct queue *pq)
{
    NODEPTR temp = pq->rear->next;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.front = NULL;
    q.rear = getNode();
    q.rear->next = q.front;

    insert(&q, 1);
    insert(&q, 5);
    insert(&q, 7);

    display_queue(&q);

    remove_q(&q);

    display_queue(&q);

    return 0;
}