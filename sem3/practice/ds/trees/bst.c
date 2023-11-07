#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int info;
    struct treeNode *left, *right;
};

typedef struct treeNode *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct treeNode)); }

void freeNode(NODEPTR node) { free(node); }

NODEPTR makeTree(int info)
{
    NODEPTR root = getNode();
    root->info = info;
    root->left = root->right = NULL;
    return root;
}

void setLeft(NODEPTR root, int info)
{
    if (root == NULL)
    {
        printf("void insertion\n");
        exit(1);
    } else if (root->left != NULL)
    {
        printf("left already exists\n");
        exit(1);
    }
    root->left = makeTree(info);
}

void setRight(NODEPTR root, int info)
{
    if (root == NULL)
    {
        printf("void insertion\n");
        exit(1);
    } else if (root->right != NULL)
    {
        printf("right already exists\n");
        exit(1);
    }
    root->right = makeTree(info);
}

void addToBst(NODEPTR root, int info)
{
    if (root->info > info)
    {
        if (root->left != NULL)
        {
            return addToBst(root->left, info);
        }
        setLeft(root, info);
    } else
    {
        if (root->right != NULL)
        {
            return addToBst(root->right, info);
        }
        setRight(root, info);
    }
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
    printf("Binary Search Tree\n");
    int option;
    int item;
    printf("Enter the first element: ");
    scanf("%d", &item);
    NODEPTR root = makeTree(item);
    do
    {
        printf("\n0. Exit\n");
        printf("1. Insert element\n");
        printf("2. Traverse tree\n");
        scanf("%d", &option);
        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element to add: ");
            scanf("%d", &item);
            addToBst(root, item);
        } else if (option == 2)
        {
            printf("pretrav: ");
            pretrav(root);
            printf("\n");
            printf("intrav: ");
            intrav(root);
            printf("\n");
            printf("posttrav: ");
            posttrav(root);
            printf("\n");
        }
    } while (option != 0);

    return 0;
}