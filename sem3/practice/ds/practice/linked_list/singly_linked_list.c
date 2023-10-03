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
        node = getNode();
        node->info = info;
        node->next = NULL;
    }
    NODEPTR newNode = getNode();
    if (node->next != NULL) {

        newNode->next = node->next;
    }
    else {
        newNode->next = NULL;
    }
    node->next = newNode;
    newNode->info = info;
}

int removeAfter(NODEPTR node)
{
    if (node->next == NULL) {
        printf("No node to remove!");
        exit(1);
    }
    NODEPTR nodeToRemove = node->next;
    node->next = node->next->next;
    int info = nodeToRemove->info;
    free(nodeToRemove);
    return info;
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
    NODEPTR head = getNode();
    head->info = 3;
    head->next = NULL;
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