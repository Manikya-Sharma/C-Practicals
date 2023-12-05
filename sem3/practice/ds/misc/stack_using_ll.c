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

int empty(struct queue *ps) { return ps->front == NULL; }

void insert(struct queue *ps, int item)
{
    NODEPTR newNode = getNode();
    newNode->info = item;
    newNode->next = ps->front;
    ps->front = newNode;
}

int remove_q(struct queue *ps)
{
    if (empty(ps))
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    NODEPTR toRemove = ps->front;
    ps->front = ps->front->next;
    int info = toRemove->info;
    free(toRemove);
    return info;
}

int getFront(struct queue *ps)
{
    if (empty(ps))
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return ps->front->info;
}

int main()
{

    int option, elem;
    struct queue s = getQueue();
    printf("**** STACK USING LINKED LIST ****\n");
    do
    {
        printf("\n0. Exit\n");
        printf("1. Insert element\n");
        printf("2. Remove element\n");
        printf("3. Display top of stack\n");
        scanf("%d", &option);
        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(&s, elem);
        } else if (option == 2)
        {
            elem = remove_q(&s);
            printf("Removed %d from the stack\n", elem);
        } else if (option == 3)
        {
            elem = getFront(&s);
            printf("Stack top: %d\n", elem);
        }
    } while (option != 0);

    return 0;
}