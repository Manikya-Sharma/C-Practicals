#include <stdio.h>
#include <stdlib.h>

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

void pretrav(NODEPTR tree) {
    if (tree != NULL) {
        printf("%d \n", tree->info);
        pretrav(tree->left);
        pretrav(tree->right);
    }
}

int main() {

    NODEPTR root = makeTree(5);
    setleft(root, 7);
    setright(root, 4);
    pretrav(root);

    return 0;
}