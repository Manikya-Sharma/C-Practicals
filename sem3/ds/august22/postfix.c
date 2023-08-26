#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 100

struct stack
{
    int top;
    int items[STACK_SIZE];
};

int empty(struct stack *ps)
{
    if (ps->top < 0)
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

int postFix(char expression[])
{
    int i = 0;
    struct stack s;
    s.top = -1;
    while (expression[i] != 0)
    {
        int current = expression[i];
        if (current >= '0' && current <= '9')
        {
            push(&s, current - '0');
        }
        else
        {
            int elem1 = pop(&s);
            int elem2 = pop(&s);
            int result;
            if (current == '+')
            {
                result = elem1 + elem2;
            }
            else if (current == '/')
            {
                result = elem2 / elem1;
            }
            else if (current == '-')
            {
                result = elem2 - elem1;
            }
            else if (current == '*')
            {
                result = elem1 * elem2;
            }
            else if (current == '$')
            {
                result = pow(elem2, elem1);
            }
            push(&s, result);
        }
        i++;
    }
    return stackTop(&s);
}

int main()
{
    char expr[20];
    printf("Enter postfix expression:");
    scanf("%s", expr);
    int result = postFix(expr);
    printf("Result is %d\n", result);
    return 0;
}