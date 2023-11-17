#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};
typedef struct Node *NODEPTR;
NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }
void freeNode(NODEPTR node) { free(node); }

NODEPTR maketree(int info)
{
    NODEPTR newNode = getNode();
    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void setLeft(NODEPTR node, int info)
{
    if (node == NULL)
        return;
    if (node->left != NULL)
        return;
    node->left = maketree(info);
}

void setRight(NODEPTR node, int info)
{
    if (node == NULL)
        return;
    if (node->right != NULL)
        return;
    node->right = maketree(info);
}

void insertToBst(NODEPTR root, int info)
{
    if (root == NULL)
        return;
    if (info > root->info)
    {
        if (root->right == NULL)
        {
            setRight(root, info);
        } else
        {
            insertToBst(root->right, info);
        }
    } else
    {
        if (root->left == NULL)
        {
            setLeft(root, info);
        } else
        {
            insertToBst(root->left, info);
        }
    }
}

int searchInBst(NODEPTR root, int val)
{
    if (root == NULL)
        return 0;
    if (root->info == val)
    {
        return 1;
    } else if (root->info < val)
    {
        return searchInBst(root->right, val);
    } else
    {
        return searchInBst(root->left, val);
    }
}
