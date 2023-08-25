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
    if (empty(ps))
        return 0;
    return ps->items[ps->top];
}

int preFix(char s[])
{
    struct stack operators;
    struct stack numbers;
    operators.top = -1;
    numbers.top = -1;

    int i = 0;
    while (s[i] != 0)
    {
        int elem = s[i];
        if (elem == '+' || elem == '-' || elem == '/' || elem == '*' || elem == '$')
        {
            push(&operators, elem);
        }
        else
        {
            if (numbers.top == 0)
            {
                int num1 = pop(&numbers);
                int num2 = elem - '0';
                char operator= pop(&operators);
                int result = 0;
                if (operator== '+')
                {
                    result = num1 + num2;
                }
                else if (operator== '/')
                {
                    result = num2 / num1;
                }
                else if (operator== '-')
                {
                    result = num2 - num1;
                }
                else if (operator== '*')
                {
                    result = num1 * num2;
                }
                else if (operator== '$')
                {
                    result = pow(num2, num1);
                }
                push(&numbers, result);
            }
            else
            {
                push(&numbers, elem - '0');
            }
        }
        i++;
    }
    return stackTop(&numbers);
}

int main()
{
    char expr[20];
    printf("Enter prefix expression:");
    scanf("%s", expr);
    int result = preFix(expr);
    printf("Result is %d\n", result);
    return 0;
}
