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

int removeAfter(NODEPTR node)
{
    NODEPTR toRemove = node->next;
    node->next = node->next->next;
    int info = toRemove->info;
    freeNode(toRemove);
    return info;
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

    NODEPTR head = NULL;
    int option, info;
    printf("===Linked List ===\n");
    do
    {
        printf("\n0. Exit\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Display\n");
        scanf("%d", &option);
        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the value to insert: ");
            scanf("%d", &info);
            if (head == NULL)
                insertAtHead(&head, info);
            else
                insertAfter(head, info);
        } else if (option == 2)
        {
            info = removeAfter(head);
            printf("Removed %d from the list", info);
        } else if (option == 3)
        {
            display(head);
        }

    } while (option != 0);
    return 0;
}