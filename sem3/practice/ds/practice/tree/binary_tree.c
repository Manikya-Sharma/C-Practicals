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

NODEPTR makeTree(int info)
{
    NODEPTR newNode = getNode();
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void setLeft(NODEPTR root, int info)
{
    if (root == NULL)
    {
        printf("Void insertion\n");
        exit(1);
    } else if (root->left != NULL)
    {
        printf("Left already exists\n");
        exit(1);
    }
    root->left = makeTree(info);
}

void setRight(NODEPTR root, int info)
{
    if (root == NULL)
    {
        printf("Void insertion");
        exit(1);
    } else if (root->right != NULL)
    {
        printf("Right already exists");
        exit(1);
    }
    root->right = makeTree(info);
}

void pretrav(NODEPTR root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    pretrav(root->left);
    pretrav(root->right);
}

void intrav(NODEPTR root)
{
    if (root == NULL)
        return;
    intrav(root->left);
    printf("%d ", root->info);
    intrav(root->right);
}

void posttrav(NODEPTR root)
{
    if (root == NULL)
        return;
    posttrav(root->left);
    posttrav(root->right);
    printf("%d ", root->info);
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

    return 0;
}