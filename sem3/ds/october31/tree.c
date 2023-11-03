#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int info;
    struct treeNode *left, *right;
};

typedef struct treeNode *PTR;

PTR getNode() { return (PTR)malloc(sizeof(struct treeNode)); }
void freeNode(PTR node) { free(node); }

PTR makeTree(int info)
{
    PTR node = getNode();
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void setLeft(PTR root, int info)
{
    if (root == NULL)
        return;
    else if (root->left != NULL)
        return;
    PTR node = makeTree(info);
    root->left = node;
}

void setRight(PTR root, int info)
{
    if (root == NULL)
        return;
    else if (root->right != NULL)
        return;
    PTR node = makeTree(info);
    root->right = node;
}

int addToBST(PTR root, int info)
{
    if (root == NULL)
        return -1;
    if (root->info > info)
    {
        if (root->left == NULL)
        {
            setLeft(root, info);
            return 0;
        } else
        {
            return addToBST(root->left, info);
        }
    } else if (root->info < info)
    {
        if (root->right == NULL)
        {
            setRight(root, info);
            return 0;
        } else
        {
            return addToBST(root->right, info);
        }
    } else
    {

        return 1; // duplicate found
    }
}

int main()
{

    int info;
    printf("Enter the root element: ");
    scanf("%d", &info);

    PTR root = makeTree(info);
    int option;

    do
    {
        printf("\n0. Quit\n1. Add new element\n");
        scanf("%d", &option);
        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element to add: ");
            scanf("%d", &info);
            int result = addToBST(root, info);
            if (result == 1)
            {
                printf("*** This is a duplicate element! ***");
            }
        }
    } while (option != 0);

    return 0;
}