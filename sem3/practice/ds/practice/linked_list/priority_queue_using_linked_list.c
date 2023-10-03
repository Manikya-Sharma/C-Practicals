#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

typedef struct Node *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }

void freeNode(NODEPTR node) { free(node); }

struct priority_queue {
    NODEPTR front;
    NODEPTR rear;
};

int empty(struct priority_queue *pq)
{
    if (pq->rear->next == pq->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct priority_queue *pq, int item)
{
    NODEPTR node = getNode();
    node->next = pq->rear->next;
    pq->rear->next = node;
    node->info = item;
}

int min_delete(struct priority_queue *pq)
{
    if (empty(pq)) {
        printf("Underflow!\n");
        exit(1);
    }
    NODEPTR temp = pq->rear->next;
    NODEPTR min_ptr = temp;
    int min_info = temp->info;
    while (temp != NULL) {
        if (temp->info < min_info) {
            min_info = temp->info;
            min_ptr = temp;
        }
        temp = temp->next;
    }
    temp = pq->rear->next;
    while (temp->next != min_ptr) {
        temp = temp->next;
    }
    NODEPTR removeNode = temp->next;
    temp->next = temp->next->next;
    int info = removeNode->info;
    freeNode(removeNode);
    return info;
}

void display_queue(struct priority_queue *pq)
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
    struct priority_queue pq;
    pq.front = NULL;
    pq.rear = getNode();
    pq.rear->next = pq.front;

    insert(&pq, 12);
    insert(&pq, 5);
    insert(&pq, 7);

    display_queue(&pq);

    min_delete(&pq);

    display_queue(&pq);

    insert(&pq, 6);

    display_queue(&pq);

    return 0;
}