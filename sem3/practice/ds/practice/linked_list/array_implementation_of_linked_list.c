#include <stdio.h>
#include <stdlib.h>
struct nodetype {
    int info, next;
};

struct nodetype NODES[100];
int avail = 0;

void initialize()
{
    for (int i = 0; i < 100; i++) {
        struct nodetype nt;
        NODES[i] = nt;
        nt.next = i + 1;
        if (i == 99) {
            nt.next = -1;
        }
    }
}

int getNode()
{
    struct nodetype node = NODES[avail];
    int p = avail;
    avail = NODES[avail].next;
    return p;
}

void freeNode(int p)
{
    NODES[p].next = avail;
    avail = p;
}

void insertAfter(int head, int item)
{
    int newNode = getNode();
    printf("NODE INFO: %d, %d\n", NODES[head].info, NODES[head].next);
    NODES[newNode].next = NODES[head].next;
    NODES[newNode].info = item;
    NODES[head].next = newNode;
}

int removeAfter(int head)
{
    if (NODES[head].next == -1) {
        printf("Underflow!\n");
        exit(1);
    }
    int toRemove = NODES[head].next;
    NODES[head].next = NODES[NODES[head].next].next;
    int data = NODES[toRemove].info;
    freeNode(toRemove);
    return data;
}

void displayLinkedList(int head)
{
    int i = head;
    while (i != -1) {
        printf("%d ", NODES[i].info);
        // printf("%d,", i);
        i = NODES[i].next;
    }
    printf("\n");
}

int main()
{
    int head = getNode();
    NODES[head].info = 0;
    NODES[head].next = -1;

    insertAfter(head, 5);
    insertAfter(head, 6);
    insertAfter(head, 10);

    // displayLinkedList(head);

    // removeAfter(NODES[head].next);
    // displayLinkedList(head);

    // removeAfter(head);
    // displayLinkedList(head);

    return 0;
}