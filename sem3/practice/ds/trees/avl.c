#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *NODEPTR;

NODEPTR makeTree(int info)
{
    NODEPTR root = (NODEPTR)malloc(sizeof(struct Node));
    root->info = info;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void setLeft(NODEPTR root, int info)
{
    if (root == NULL)
    {
        printf("Void insertion\n");
        exit(1);
    }
    if (root->left != NULL)
    {
        printf("Left already exist\n");
        exit(1);
    }
    root->left = makeTree(info);
}

void setRight(NODEPTR root, int info)
{
    if (root == NULL)
    {
        printf("Void insertion\n");
        exit(1);
    }
    if (root->right != NULL)
    {
        printf("Right already exist\n");
        exit(1);
    }
    root->right = makeTree(info);
}

void freeTree(NODEPTR root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void preTrav(NODEPTR root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preTrav(root->left);
    preTrav(root->right);
}

void height(NODEPTR node, int *curr, int *max_height)
{
    if (curr == NULL)
    {
        int h = 0;
        curr = &h;
    }
    if (node == NULL)
    {
        if (*curr > *max_height)
        {
            *max_height = *curr;
        }
        return;
    }

    int newHeight = *curr + 1;

    height(node->left, &newHeight, max_height);
    height(node->right, &newHeight, max_height);
}

int main()
{

    /* INITIALIZATION */
    NODEPTR root = makeTree(96);

    /* TREE CREATION */

    setLeft(root, 85);
    setLeft(root->left, 64);
    setRight(root->left, 90);

    setRight(root, 110);

    /* DISPLAY THE TREE */
    preTrav(root);

    /* ENDING ROUTINES */
    printf("\n");
    freeTree(root);
    return 0;
}