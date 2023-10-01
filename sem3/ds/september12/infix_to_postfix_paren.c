#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct stack {
    int top;
    int items[STACK_SIZE];
};

int empty(struct stack *ps)
{
    if (ps->top < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int pop(struct stack *ps)
{
    if (empty(ps)) {
        exit(1);
    }
    return ps->items[ps->top--];
}

void push(struct stack *ps, int item) { ps->items[++ps->top] = item; }

int stackTop(struct stack *ps) { return ps->items[ps->top]; }

int operand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$' ||
        ch == '(' || ch == ')') {
        return 1;
    }
    return 0;
}

int prec(char op1, char op2)
{
    // lowest precedence
    if (op1 == '(') {
        return 0;
    }
    else if (op2 == ')') {
        return 1;
    }
    if (op1 == '$') {
        return 1;
    }
    else if (op2 == '$') {
        return 0;
    }

    if (op1 == '*') {
        return 1;
    }
    else if (op2 == '*') {
        return 0;
    }

    if (op1 == '/') {
        return 1;
    }
    else if (op2 == '/') {
        return 0;
    }
    if (op1 == '+') {
        return 1;
    }
    else if (op2 == '+') {
        return 0;
    }
    if (op1 == '-') {
        return 1;
    }
    else if (op2 == '-') {
        return 0;
    }
    return 1;
}

char *infix_to_postfix(char input[])
{
    struct stack op_stk;
    op_stk.top = -1;
    char *postfix = (char *)malloc(100 * (sizeof(char)));
    int j = 0;
    int i = 0;
    while (input[i] != '\0') {
        char symb = input[i];

        if (!operand(symb)) {
            postfix[j++] = symb;
        }
        else {
            if (symb == ')') {
                while (1) {
                    int temp_symb = pop(&op_stk);
                    if (temp_symb == '(') {
                        break;
                    }
                    postfix[j++] = temp_symb;
                }
                i++;
                continue;
            }
            while (!empty(&op_stk) && prec(stackTop(&op_stk), symb)) {
                char top_symb = pop(&op_stk);
                postfix[j++] = top_symb;
            }
            push(&op_stk, symb);
        }
        i++;
    }

    while (!empty(&op_stk)) {
        char top_symb = pop(&op_stk);
        postfix[j++] = top_symb;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[100];
    printf("Enter the infix: ");
    scanf("%s", infix);

    char *postfix = infix_to_postfix(infix);
    printf("%s\n", postfix);
    return 0;
}