#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100

struct stack
{
    int items[MAX_STACK];
    int top;
};

int empty_stack(struct stack *ps) { return ps->top == -1; }

void push(struct stack *ps, int item) { ps->items[++ps->top] = item; }

int pop(struct stack *ps) { return ps->items[ps->top--]; }

int stackTop(struct stack *ps) { return ps->items[ps->top]; }

struct queue
{
    struct stack main;
    struct stack aux;
};

int empty(struct queue *pq) { return empty_stack(&pq->main); }

void insert(struct queue *pq, int item) { push(&pq->main, item); }

int remove_q(struct queue *pq)
{
    while (!empty_stack(&pq->main))
    {
        push(&pq->aux, pop(&pq->main));
    }
    int item = pop(&pq->aux);
    while (!empty_stack(&pq->aux))
    {
        push(&pq->main, pop(&pq->aux));
    }
    return item;
}

void display(struct queue *pq)
{
    for (int i = 0; i <= pq->main.top; i++)
    {
        printf("%d ", pq->main.items[i]);
    }
    printf("\n");
}

int main()
{
    int option, elem;
    struct queue q;
    q.main.top = -1;
    q.aux.top = -1;
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