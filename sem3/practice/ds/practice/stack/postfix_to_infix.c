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

/* postfix to infix  */

void postfix_to_infix(char postfix[])
{
    struct stack numstk;
    numstk.top = -1;
    int i = 0, flag = 0;
    char infix[100];
    int k = 0;
    while (postfix[i] != '\0') {
        char symb = postfix[i];
        if (!isOperator(symb)) {
            push(&numstk, symb);
        }
        else {
            if (!flag) {
                /* first time operator  */
                char op2 = pop(&numstk);
                char op1 = pop(&numstk);
                infix[k++] = op1;
                infix[k++] = symb;
                infix[k++] = op2;
                flag = 1;
            }
            else {
                char op2 = pop(&numstk);
                infix[k++] = symb;
                infix[k++] = op2;
            }
        }
        i++;
    }
    infix[k] = '\0';
    printf("Infix: %s\n", infix);
}

int main()
{

    char infix[100];
    printf("Enter the postfix: ");
    scanf("%s", infix);
    postfix_to_infix(infix);
    return 0;
}