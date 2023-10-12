#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node* NODEPTR;

NODEPTR getNode() {
    NODEPTR node = (NODEPTR)malloc(sizeof(struct Node));
    return node;
}

void freeNode(NODEPTR node) {
    free(node);
}

void insertAfter(NODEPTR node, int item) {
    NODEPTR newNode = getNode();
    newNode->info = item;
    newNode->next = node->next;
    node->next = newNode;
}


int main() {
    NODEPTR head = getNode();
    insertAfter(head, 5);
    insertAfter(head, 10);
    return 0;
}
