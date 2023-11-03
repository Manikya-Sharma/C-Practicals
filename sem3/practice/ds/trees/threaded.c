#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left, *right;
    int isThread;
};

typedef struct Node *NODEPTR;

NODEPTR getNode()
{
    NODEPTR node = (NODEPTR)malloc(sizeof(struct Node));
    return node;
}

void freeNode(NODEPTR node) { free(node); }

NODEPTR makeTree(int info)
{
    NODEPTR root = getNode();
    root->left = NULL;
    root->right = NULL;
    root->info = info;
    root->isThread = 0;
    return root;
}

void setLeft(NODEPTR node, int info)
{
    if (node == NULL)
    {
        // printf("%d ", info);
        printf("Void insertion at left\n");
        return;
    } else if (node->left != NULL)
    {
        printf("Left already exists\n");
        return;
    }
    NODEPTR newNode = makeTree(info);
    newNode->right = node;
    newNode->isThread = 1;
    node->left = newNode;
}

void setRight(NODEPTR node, int info)
{
    if (node == NULL)
    {
        // printf("%d ", info);
        printf("Void insertion at right\n");
        return;
    } else if (node->right != NULL && !(node->isThread))
    {
        printf("Right already exists\n");
        return;
    }
    NODEPTR newNode = makeTree(info);
    if (node->isThread)
    {
        newNode->right = node->right;
        newNode->isThread = 1;
        node->isThread = 0;
    }
    node->right = newNode;
}

NODEPTR leftMost(NODEPTR node)
{
    if (node == NULL)
    {
        return NULL;
    }
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

void intrav(NODEPTR root)
{
    NODEPTR curr = leftMost(root);
    while (curr != NULL)
    {
        printf("%d ", curr->info);

        if (curr->isThread)
        {
            curr = curr->right;
        } else
        {
            curr = leftMost(curr->right);
        }
    }
}

int main()
{

    NODEPTR root = makeTree(6);
    setLeft(root, 3);
    setLeft(root->left, 1);

    setRight(root->left, 5);
    setRight(root, 8);

    setLeft(root->right, 7);
    setRight(root->right, 11);
    setLeft(root->right->right, 9);
    setRight(root->right->right, 13);

    intrav(root);
    printf("\n");

    return 0;
}