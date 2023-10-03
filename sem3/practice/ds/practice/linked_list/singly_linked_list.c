#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

typedef struct Node *NODEPTR;

NODEPTR getNode()
{
    NODEPTR node = (NODEPTR)malloc(sizeof(struct Node));
    return node;
}

void freeNode(NODEPTR node) { free(node); }

void insertAfter(NODEPTR node, int info)
{
    if (node == NULL) {
        printf("Invalid! Cant append to NULL\n");
        exit(1);
    }
    else if (node->next == NULL) {
        printf("Invalid! Use insertEnd instead\n");
        exit(1);
    }
    NODEPTR newNode = getNode();
    newNode->next = node->next;
    newNode->next = NULL;
    node->next = newNode;
    newNode->info = info;
}

int removeAfter(NODEPTR node)
{
    if (node->next == NULL) {
        printf("No node to remove!\n");
        exit(1);
    }
    NODEPTR nodeToRemove = node->next;
    node->next = node->next->next;
    int info = nodeToRemove->info;
    free(nodeToRemove);
    return info;
}

void voidInsertion(NODEPTR head, int info)
{
    if (head != NULL) {
        printf("Invalid! Only void insertion allowed!\n");
        exit(1);
    }
    else {
        head = getNode();
        head->info = info;
        head->next = NULL;
    }
}

void displayLinkedList(NODEPTR head)
{
    NODEPTR temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    NODEPTR head = NULL;
    voidInsertion(head, 5);
    insertAfter(head, 5);
    insertAfter(head, 6);
    insertAfter(head, 10);

    displayLinkedList(head);

    removeAfter(head->next);
    displayLinkedList(head);

    removeAfter(head);
    displayLinkedList(head);

    return 0;
}