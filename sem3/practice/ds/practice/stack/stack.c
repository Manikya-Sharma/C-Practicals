// ? STACK USING STRUCT

#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

struct stack {
    int top;
    int items[STACK_SIZE];
};

int empty(struct stack *ps)
{
    if (ps->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int pop(struct stack *ps)
{
    if (empty(ps)) {
        printf("Underflow!\n");
        exit(1);
    }
    return ps->items[ps->top--];
}

void push(struct stack *ps, int elem)
{
    if (ps->top == STACK_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    ps->items[++ps->top] = elem;
}

int stackTop(struct stack *ps) { return ps->items[ps->top]; }

void showStack(struct stack *ps)
{
    for (int i = 0; i < ps->top; i++) {
        printf("%d ", ps->items[i]);
    }
    printf("\n");
}

int main()
{
    struct stack s;
    s.top = -1;

    push(&s, 5);
    push(&s, 7);
    push(&s, 9);
    push(&s, 3);
    push(&s, 1);

    showStack(&s);

    pop(&s);
    pop(&s);

    showStack(&s);

    return 0;
}