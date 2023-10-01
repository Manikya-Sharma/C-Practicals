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
        printf("Underflow!\n");
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

int operand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$')
    {
        return 1;
    }
    return 0;
}

int prec(char op1, char op2)
{
    if (op1 == '$')
    {
        return 1;
    }
    else if (op2 == '$')
    {
        return 0;
    }

    if (op1 == '*')
    {
        return 1;
    }
    else if (op2 == '*')
    {
        return 0;
    }

    if (op1 == '/')
    {
        return 1;
    }
    else if (op2 == '/')
    {
        return 0;
    }
    if (op1 == '+')
    {
        return 1;
    }
    else if (op2 == '+')
    {
        return 0;
    }
    if (op1 == '-')
    {
        return 1;
    }
    else if (op2 == '-')
    {
        return 0;
    }
    return 1;
}

char *reverse(char *str)
{
    char *reversed_string = (char *)malloc(50 * sizeof(char));
    int len = 0;
    while (str[len] != 0)
    {
        len++;
    }
    int j = len - 1, i = 0;
    while (j >= 0)
    {
        reversed_string[j] = str[i];
        j--;
        i++;
    }
    reversed_string[len] = 0;
    return reversed_string;
}

char *infix_to_prefix(char input[])
{
    struct stack op_stack;
    struct stack num_stack;
    struct stack temp_stack;
    op_stack.top = -1;
    num_stack.top = -1;
    temp_stack.top = -1;

    int i = 0;
    while (input[i] != 0)
    {
        char symb = input[i];
        if (operand(symb))
        {
            push(&op_stack, symb);
        }
        else
        {
            push(&num_stack, symb);
        }
        i++;
    }
    char *reversed_string = (char *)malloc(50 * sizeof(char));
    int j = 0;

    // add the first number
    reversed_string[j++] = pop(&num_stack);

    while (!empty(&num_stack))
    {
        struct stack temp_op;
        struct stack temp_num;

        temp_op.top = -1;

        while (!empty(&op_stack))
        {
            char op = pop(&op_stack);
            reversed_string[j++] = pop(&num_stack);
            push(&temp_op, op);
            if (empty(&op_stack))
            {
                reversed_string[j++] = op;
                break;
            }
            while (prec(stackTop(&op_stack), op))
            {
                push(&temp_op, pop(&op_stack));
                reversed_string[j++] = pop(&num_stack);
                if (empty(&op_stack))
                {
                    break;
                }
            }
            while (!empty(&temp_op))
            {
                reversed_string[j++] = pop(&temp_op);
            }
        }
    }
    reversed_string[j] = '\0';
    return reverse(reversed_string);
}

int main()
{
    printf("Enter the infix: ");
    char infix[50];
    scanf("%s", infix);
    char *prefix = infix_to_prefix(infix);
    printf("%s\n", prefix);
    return 0;
}
