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

void reverse(char arr[])
{
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        char temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

/*  infix to prefix */

void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
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
                if (empty(&opstk)) {
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
}

void infix_to_prefix(char infix[])
{
    char prefix[100];
    reverse(infix);
    infix_to_postfix(infix, prefix);
    reverse(prefix);
    printf("Prefix: %s\n", prefix);
}

int main()
{

    char infix[100], prefix[100];
    printf("Enter the infix: ");
    scanf("%s", infix);
    infix_to_prefix(infix);
    return 0;
}