// convert to inorder threaded
#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int info;
    struct treeNode *left, *right;
    int isThread;
};

typedef struct treeNode *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct treeNode)); }

void freeNode(NODEPTR node) { free(node); }

NODEPTR makeTree(int info)
{
    NODEPTR root = getNode();
    root->info = info;
    root->left = root->right = NULL;
    root->isThread = 0;
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
    NODEPTR newNode = makeTree(info);
    root->left = newNode;
    newNode->isThread = 1;
    newNode->right = root;
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
    NODEPTR newNode = makeTree(info);
    if (root->isThread)
    {
        newNode->right = root->right;
        newNode->isThread = 1;
        root->isThread = 0;
    }
    root->right = newNode;
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
            printf("intrav: ");
            intrav(root);
            printf("\n");
        }
    } while (option != 0);

    return 0;
}