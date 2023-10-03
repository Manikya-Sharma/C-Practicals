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

int pow(int a, int b)
{
    if (b == 0) {
        return 1;
    }
    return a * pow(a, b - 1);
}

/* evaluate postfix */

int evaluate(char postfix[])
{
    struct stack opstk;
    opstk.top = -1;
    int i = 0;
    while (postfix[i] != '\0') {
        char symb = postfix[i];
        if (isOperator(symb)) {
            int op1 = pop(&opstk) - '0';
            int op2 = pop(&opstk) - '0';
            int result;
            switch (symb) {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op2 / op1;
                break;
            case '$':
                result = pow(op2, op1);
                break;
            }
            push(&opstk, result+'0');
        }
        else {
            push(&opstk, symb);
        }
        i++;
    }
    return pop(&opstk)-'0';
}

/* main */
int main()
{
    char evalMe[100];
    printf("Enter the postfix: ");
    scanf("%s", evalMe);
    int answer = evaluate(evalMe);
    printf("Answer: %d\n", answer);
    return 0;
}