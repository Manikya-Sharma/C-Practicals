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

NODEPTR getHead(int info)
{
    NODEPTR head = getNode();
    head->info = info;
    head->next = head;
    return head;
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
    if (node == NULL)
    {
        printf("Already empty!\n");
        return -1;
    }
    NODEPTR toRemove = node->next;
    node->next = node->next->next;
    int info = toRemove->info;
    freeNode(toRemove);
    return info;
}

void display(NODEPTR node)
{
    NODEPTR temp = node;
    do
    {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != node);

    printf("\n");
}
int main()
{
    int elem;
    printf("Circular Linked List\n");
    NODEPTR head = NULL;
    int option;
    do
    {
        printf("\n0. Exit\n");
        printf("1. Insert an element\n");
        printf("2. Remove an element\n");
        printf("3. Display\n");

        scanf("%d", &option);

        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element:");
            scanf("%d", &elem);
            if (head == NULL)
                head = getHead(elem);
            else
                insertAfter(head, elem);
        } else if (option == 2)
        {
            elem = removeAfter(head);
            printf("Removed: %d", elem);
        } else if (option == 3)
        {
            display(head);
        }

    } while (option != 0);
    return 0;
}
