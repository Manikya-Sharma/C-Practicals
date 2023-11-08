#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }
void freeNode(NODEPTR node) { free(node); }

void insertAtHead(NODEPTR *head, int info)
{
    NODEPTR newNode = getNode();
    newNode->info = info;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(NODEPTR node, int info)
{
    NODEPTR newNode = getNode();
    newNode->info = info;
    newNode->next = node->next;
    node->next = newNode;
}

void clear(NODEPTR head)
{
    if (head == NULL)
    {
        return;
    }
    clear(head->next);
    freeNode(head);
}

NODEPTR mid(NODEPTR head)
{
    NODEPTR slow = head;
    NODEPTR fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

NODEPTR merge(NODEPTR node1, NODEPTR node2)
{
    NODEPTR newNode = getNode();
    newNode->info = -1;
    NODEPTR temp = newNode;

    while (node1 != NULL && node2 != NULL)
    {
        if (node1->info < node2->info)
        {
            temp->next = node1;
            temp = node1;
            node1 = node1->next;
        } else
        {
            temp->next = node2;
            temp = node2;
            node2 = node2->next;
        }
    }
    while (node1 != NULL)
    {
        temp->next = node1;
        node1 = node1->next;
        temp = node1;
    }
    while (node2 != NULL)
    {
        temp->next = node2;
        node2 = node2->next;
        temp = node2;
    }
    temp = newNode->next;
    free(newNode);
    return temp;
}

void mergeSort(NODEPTR *head)
{
    if (head == NULL || *(head) == NULL || (*head)->next == NULL)
    {
        return;
    }
    NODEPTR node1 = *head;
    NODEPTR temp = mid(*head);
    NODEPTR node2 = temp->next;
    temp->next = NULL;

    mergeSort(&node1);
    mergeSort(&node2);

    *head = merge(node1, node2);
}

void display(NODEPTR head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    NODEPTR head = getNode();
    NODEPTR node = head;
    node->info = 10;
    node->next = getNode();
    node = node->next;
    node->info = 1;
    node->next = getNode();
    node = node->next;
    node->info = 5;
    node->next = getNode();
    node = node->next;
    node->info = 3;
    node->next = getNode();
    node = node->next;
    node->info = 7;
    node->next = getNode();
    node = node->next;
    node->info = 4;
    node->next = NULL;

    display(head);

    mergeSort(&head);

    display(head);

    clear(head);
    return 0;
}