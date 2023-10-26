#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct stack
{
    int top;
    int items[STACK_SIZE];
};

int empty(struct stack *ps)
{
    if (ps->top == -1)
    {
        return 1;
    } else
    {
        return 0;
    }
}

int pop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Underflow!\n");
        exit(1);
    }
    return ps->items[ps->top--];
}

void push(struct stack *ps, int item)
{
    if (ps->top >= STACK_SIZE - 1)
    {
        printf("Overflow!");
        exit(1);
    }
    ps->items[++ps->top] = item;
}

int stackTop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Underflow!\n");
        exit(1);
    }
    return ps->items[ps->top];
}

void display(struct stack *ps)
{
    for (int i = 0; i <= ps->top; i++)
    {
        printf("%d ", ps->items[i]);
    }
    printf("\n");
}

int main()
{

    struct stack s;
    s.top = -1;

    int option, item;
    printf("=== STACK ===\n");
    do
    {
        printf("\nEnter the option\n");
        printf("0. Exit\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Stack Top\n");
        printf("4. Display contents of stack\n");

        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("Bye\n");
            break;
        case 1:
            printf("Enter the element to push\n");
            scanf("%d", &item);
            push(&s, item);
            break;
        case 2:
            item = pop(&s);
            printf("Removed %d from the stack\n", item);
            break;
        case 3:
            printf("Stack top is %d\n", stackTop(&s));
            break;
        case 4:
            display(&s);
            break;
        default:
            printf("Please enter a valid option\n");
        }

    } while (option != 0);

    return 0;
}