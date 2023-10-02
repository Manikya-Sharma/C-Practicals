#include<stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

typedef struct Node * NODEPTR;

NODEPTR getNode() {
    NODEPTR node = (NODEPTR)malloc(sizeof(struct Node));
    node->next = NULL;
    return node;
}

void freeNode(NODEPTR node){
    free(node);
}

void insertAfter(NODEPTR node, int item) {
    NODEPTR newNode = getNode();
    newNode->next = node->next->next;
    node->next = newNode;
    newNode->info = item;
}

void push_stack(NODEPTR head, int info) {
    NODEPTR temp = head;
    while (temp ->next != NULL) {
        temp = temp->next;
    }

}