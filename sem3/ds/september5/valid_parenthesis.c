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

int valid_parenthesis(char arr[])
{
    struct stack s;
    s.top = -1;
    int i = 0;
    while (arr[i] != '\0')
    {
        char elem = arr[i];
        if (elem == '(' || elem == '[' || elem == '{'){
            push(&s, arr[i]);
        }
        else
        {
            if (s.top == -1)
                return 0;
            char popped_elem = pop(&s);
            if (elem == ')')
            {
                if (popped_elem != '(')
                    return 0;
            }
            else if (elem == ']')
            {
                if (popped_elem != '[')
                    return 0;
            }

            else if (elem == '}')
            {
                if (popped_elem != '{')
                    return 0;
            }
        }
        i++;
    }
    if (s.top != -1)
        return 0;
    return 1;
}

int main()
{
    printf("Please enter parenthesis:-\n");
    char expression[30];
    scanf("%s", expression);
    if (valid_parenthesis(expression))
    {
        printf("The parenthesis are valid\n");
    }
    else
    {
        printf("The parenthesis are not valid\n");
    }
    return 0;
}