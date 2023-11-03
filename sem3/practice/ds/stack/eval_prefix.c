/* INCOMPLETE */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

struct stack
{
    int items[STACK_SIZE];
    int top;
};

struct stack getStack()
{
    struct stack st;
    st.top = -1;
    return st;
}

int empty(struct stack *ps) { return ps->top == -1; }

void push(struct stack *ps, int item)
{
    if (ps->top == STACK_SIZE - 1)
    {
        printf("Overflow!\n");
        exit(1);
    }
    ps->items[++ps->top] = item;
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

void display(struct stack *ps)
{
    for (int i = 0; i <= ps->top; i++)
    {
        printf("%d ", ps->items[i]);
    }
    printf("\n");
}

int operand(char symb)
{
    if (symb == '+' || symb == '-' || symb == '*' || symb == '$' || symb == '/')
    {
        return 1;
    }
    return 0;
}

int main()
{
    char prefix[100];
    printf("Enter the prefix string:");
    scanf("%s", prefix);
}