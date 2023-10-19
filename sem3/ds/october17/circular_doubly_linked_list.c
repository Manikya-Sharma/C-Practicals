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

void insertAfter(NODEPTR node, int item)
{
    NODEPTR newNode = getNode();
    newNode->right = node->right;
    node->right = newNode;
    newNode->left = node;
    newNode->info = item;
}

int removeNode(NODEPTR node)
{
    node->left->right = node->right;
    node->right->left = node->left;
    int x = node->info;
    freeNode(node);
    return x;
}

void printLinkedList(NODEPTR head)
{
    NODEPTR temp1 = head;
    NODEPTR temp2 = head;
    while (temp1 != temp2)
    {
        printf("%d ", temp1->info);
        temp1 = temp1->right;
    }
    printf("\n");
}

int main()
{
    NODEPTR head = getNode();
    head->left = NULL;
    head->right = NULL;

    insertAfter(head, 5);
    insertAfter(head, 7);

    printLinkedList(head);

    // insertAfter(head->right, 15);

    // printLinkedList(head);

    // removeNode(head);

    // printLinkedList(head);

    return 0;
}