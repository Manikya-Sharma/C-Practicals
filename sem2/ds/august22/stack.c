#include <stdio.h>

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
    }
    else
    {
        return 0;
    }
}

int pop(struct stack *ps)
{
    if (empty(ps))
    {
        exit(1);
    }
    return ps->items[ps->top--];
}

void push(struct stack *ps, int item)
{
    ps->items[++ps->top] = item;
}

int stackTop(struct stack *ps)
{
    return ps->items[ps->top];
}

int main()
{

    return 0;
}