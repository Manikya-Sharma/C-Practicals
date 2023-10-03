#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

typedef struct Node *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }

void freeode(NODEPTR node) { free(node); }

struct stack {
    NODEPTR top;
};

int empty(struct stack *ps)
{
    if (ps->top == NULL) {
        return 1;
    }
    return 0;
}

void push(struct stack *ps, int item)
{
    NODEPTR node = getNode();
    node->next = ps->top;
    node->info = item;
    ps->top = node;
}

int pop(struct stack *ps)
{
    int item = ps->top->info;
    NODEPTR removeNode = ps->top;
    ps->top = ps->top->next;
    free(removeNode);
    return item;
}

void showStack(struct stack *ps)
{
    NODEPTR temp = ps->top;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct stack st;
    st.top = NULL;

    push(&st, 5);
    push(&st, 7);
    push(&st, 9);
    push(&st, 3);
    push(&st, 1);

    showStack(&st);

    pop(&st);
    pop(&st);

    showStack(&st);

    return 0;
}