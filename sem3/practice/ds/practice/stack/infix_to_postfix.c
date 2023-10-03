#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

/* definition of stack */
struct stack {
    int top;
    int items[STACKSIZE];
};

int empty(struct stack *ps) { return ps->top == -1; }

int pop(struct stack *ps)
{
    if (empty(ps)) {
        printf("Underflow!\n");
        exit(1);
    }
    return ps->items[ps->top--];
}

void push(struct stack *ps, int item) { ps->items[++ps->top] = item; }

int stackTop(struct stack *ps)
{
    if (empty(ps)) {
        printf("Underflow!\n");
        exit(1);
    }
    return ps->items[ps->top];
}

/* helper functions */

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') {
        return 1;
    }
    return 0;
}

int prec(char op1, char op2)
{
    char operators[5] = {'$', '*', '/', '+', '-'};
    int prec1 = -1;
    int prec2 = -1;
    for (int i = 0; i < 5; i++) {
        if (op1 == operators[i]) {
            prec1 = i;
        }
        else if (op2 == operators[i]) {
            prec2 = i;
        }
    }
    return prec1 < prec2;
}

/*  infix to postfix */

void infix_to_postfix(char infix[])
{
    int i = 0, j = 0;
    char postfix[100];
    struct stack opstk;
    opstk.top = -1;
    while (infix[i] != 0) {
        char symb = infix[i];
        if (!isOperator(symb)) {
            postfix[j++] = symb;
        }
        else {
            if (empty(&opstk)) {
                push(&opstk, symb);
                i++;
                continue;
            }
            while (prec(stackTop(&opstk), symb)) {
                // symb has lower precedence than stackTop
                char op = pop(&opstk);
                postfix[j++] = op;
                if (empty(&opstk))  {
                    break;
                }
            }
            push(&opstk, symb);
        }
        i++;
    }
    while (!empty(&opstk)) {
        postfix[j++] = pop(&opstk);
    }
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main()
{

    char infix[100];
    printf("Enter the infix: ");
    scanf("%s", infix);
    infix_to_postfix(infix);
    return 0;
}