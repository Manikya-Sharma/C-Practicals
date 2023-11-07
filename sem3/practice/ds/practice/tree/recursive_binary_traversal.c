#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100

struct Node
{
    int info;
    struct Node *left, *right;
};
typedef struct Node *NODEPTR;
NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }
void freeNode(NODEPTR node) { free(node); }

NODEPTR makeTree(int info)
{
    NODEPTR node = getNode();
    node->info = info;
    node->left = node->right = NULL;
    return node;
}

void setLeft(NODEPTR node, int info)
{
    if (node == NULL)
    {
        printf("Void insertion\n");
        exit(1);
    } else if (node->left != NULL)
    {
        printf("left already exists\n");
        exit(1);
    }
    node->left = makeTree(info);
}

void setRight(NODEPTR node, int info)
{
    if (node == NULL)
    {
        printf("Void insertion\n");
        exit(1);
    } else if (node->right != NULL)
    {
        printf("right already exists\n");
        exit(1);
    }
    node->right = makeTree(info);
}

struct stack
{
    NODEPTR items[MAX_STACK];
    int top;
};

int empty(struct stack *ps) { return (ps->top == -1); }

void push(struct stack *ps, NODEPTR item) { ps->items[++ps->top] = item; }

NODEPTR pop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Underflow\n");
        exit(1);
    }
    return ps->items[ps->top--];
}

NODEPTR stackTop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Underflow\n");
        exit(1);
    }
    return ps->items[ps->top];
}

void pretrav(NODEPTR root)
{

    struct stack s;
    s.top = -1;

    while (root != NULL)
    {
        if (root->right != NULL)
        {
            push(&s, root->right);
        }
        printf("%d ", root->info);
        root = root->left;
    }
    while (!empty(&s))
    {
        root = pop(&s);
        // exact same while loop
        while (root != NULL)
        {
            if (root->right != NULL)
            {
                push(&s, root->right);
            }
            printf("%d ", root->info);
            root = root->left;
        }
    }
}

void intrav(NODEPTR root)
{

    struct stack s;
    s.top = -1;

    while (root != NULL)
    {
        push(&s, root);
        root = root->left;
    }

    while (!empty(&s))
    {
        root = pop(&s);
        printf("%d ", root->info);
        root = root->right;
        // exact same while loop
        while (root != NULL)
        {
            push(&s, root);
            root = root->left;
        }
    }
}

void posttrav(NODEPTR root)
{
    // todo
}

void clear(NODEPTR root)
{
    if (root == NULL)
        return;
    clear(root->left);
    clear(root->right);
    freeNode(root);
}

int main()
{
    NODEPTR root = makeTree(5);
    setLeft(root, 7);
    setLeft(root->left, 15);
    setLeft(root->left->left, 3);

    setRight(root, 14);
    setRight(root->left->left, 8);

    setLeft(root->right, 20);
    setRight(root->right->left, 14);

    printf("pretrav:  ");
    pretrav(root);
    printf("\n");

    printf("intrav:   ");
    intrav(root);
    printf("\n");

    printf("posttrav: ");
    posttrav(root);
    printf("\n");

    clear(root);

    return 0;
}