#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left, *right;
};

typedef struct Node *NODEPTR;

NODEPTR getNode()
{
    NODEPTR node = (NODEPTR)malloc(sizeof(struct Node));
    return node;
}

void freeNode(NODEPTR node) { free(node); }

NODEPTR insertBeggining(NODEPTR head, int elem)
{
    NODEPTR newNode = getNode();
    newNode->info = elem;
    head->left = newNode;
    newNode->right = head;
    newNode->left = NULL;
    return newNode;
}

void insertAfter(NODEPTR node, int item)
{
    NODEPTR newNode = getNode();
    newNode->right = node->right;
    node->right->left = newNode;
    node->right = newNode;
    newNode->left = node;
    newNode->info = item;
}

int deleteAfter(NODEPTR node)
{
    NODEPTR toRemove = node->right;
    node->right = node->right->right;
    node->right->left = node;
    int value = toRemove->info;
    free(toRemove);
    return value;
}

void printLinkedList(NODEPTR head)
{
    NODEPTR temp = head;
    while (temp->right != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->right;
    }
    printf("\n");
}

int main()
{
    NODEPTR head = getNode();
    head->left = NULL;
    head->right = NULL;

    head = insertBeggining(head, 5);
    head = insertBeggining(head, 7);

    printLinkedList(head);

    insertAfter(head->right, 15);

    printLinkedList(head);

    deleteAfter(head);

    printLinkedList(head);

    return 0;
}