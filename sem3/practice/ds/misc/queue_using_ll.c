#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node *NODEPTR;
NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }

struct queue
{
    NODEPTR front;
};

struct queue getQueue()
{
    struct queue s;
    s.front = NULL;
    return s;
}

int empty(struct queue *pq) { return pq->front == NULL; }

void insert(struct queue *pq, int item)
{
    NODEPTR newNode = getNode();
    newNode->info = item;
    newNode->next = NULL;
    NODEPTR temp = pq->front;
    if (empty(pq))
    {
        pq->front = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int remove_q(struct queue *pq)
{
    if (empty(pq))
    {
        printf("Queue Empty!\n");
        exit(1);
    }
    NODEPTR toRemove = pq->front;
    pq->front = pq->front->next;
    int info = toRemove->info;
    free(toRemove);
    return info;
}

void display(struct queue *pq)
{
    NODEPTR temp = pq->front;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    int option, elem;
    struct queue q = getQueue();
    printf("**** QUEUE USING LINKED LIST ****\n");
    do
    {
        printf("\n0. Exit\n");
        printf("1. Insert element\n");
        printf("2. Remove element\n");
        printf("3. Display queue\n");
        scanf("%d", &option);
        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(&q, elem);
        } else if (option == 2)
        {
            elem = remove_q(&q);
            printf("Removed %d from the stack\n", elem);
        } else if (option == 3)
        {
            display(&q);
        }
    } while (option != 0);

    return 0;
}