#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100

struct Node
{
    int info;
    struct Node *left, *right;
};

typedef struct Node *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }

void freeNode(NODEPTR node) { free(node); }

NODEPTR makeTree(int data)
{
    NODEPTR node = getNode();
    node->info = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void setleft(NODEPTR p, int x)
{
    if (p == NULL)
    {
        printf("void insertion\n");
        return;
    } else if (p->left != NULL)
    {
        printf("left already exists\n");
        return;
    } else
    {
        p->left = makeTree(x);
    }
}

void setright(NODEPTR p, int x)
{
    if (p == NULL)
    {
        printf("void insertion\n");
        return;
    } else if (p->right != NULL)
    {
        printf("right already exists\n");
        return;
    } else
    {
        p->right = makeTree(x);
    }
}

void posttrav(NODEPTR node)
{
    if (node == NULL)
    {
        return;
    }
    posttrav(node->left);
    posttrav(node->right);
    printf("%d ", node->info);
}

struct stack
{
    int top;
    NODEPTR items[MAXSTACK];
};

void push(struct stack *s, NODEPTR item) { s->items[++s->top] = item; }

NODEPTR pop(struct stack *s) { return s->items[s->top--]; }

int empty(struct stack *s) { return s->top == -1; }

void intrav2(NODEPTR tree)
{
    struct stack s;
    NODEPTR p;

    s.top = -1;
    p = tree;
    do
    {
        while (p != NULL)
        {
            push(&s, p);
            p = p->left;
        }
        if (!empty(&s))
        {
            p = pop(&s);
            printf("%d ", p->info);
            p = p->right;
        }
    } while (!empty(&s) || p != NULL);
}

void posttrav2() {}

int main()
{

    /*

                5
              /  \
             7   4
           /    / \
          9    2  3
          \   /
          10 6
    */

    NODEPTR root = makeTree(5);
    setleft(root, 7);
    setleft(root->left, 9);
    setright(root->left->left, 10);
    setright(root, 4);
    setleft(root->right, 2);
    setleft(root->right->left, 6);
    setright(root->right, 3);

    posttrav(root);
    printf("\n");
    intrav2(root);
    printf("\n");

    return 0;
}