#define MAX_QUEUE 100
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int items[MAX_QUEUE];
    int front, rear;
};

int empty(struct queue *pq) { return (pq->front < pq->rear); }

void insert(struct queue *pq, int item)
{
    if (pq->front == MAX_QUEUE - 1)
    {
        printf("Overflow!");
        exit(1);
    }
    pq->items[++pq->front] = item;
}

int remove_q(struct queue *pq)
{
    if (empty(pq))
    {
        printf("Underflow!\n");
        exit(1);
    }
    return pq->items[pq->rear++];
}

void display(struct queue *pq)
{
    for (int i = pq->rear; i <= pq->front; i++)
    {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.front = -1;
    q.rear = 0;

    printf("****** QUEUE OPERATIONS ******\n");
    int choice;
    int item;
    do
    {
        printf("\n0. Quit\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Print\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Thank you!\n");
            break;
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &item);
            insert(&q, item);
            printf("Added %d to the queue", item);
            break;
        case 2:
            item = remove_q(&q);
            printf("Removed %d from queue", item);
            break;
        case 3:
            display(&q);
            break;
        default:
            printf("Please enter a valid option");
        }

    } while (choice != 0);

    return 0;
}