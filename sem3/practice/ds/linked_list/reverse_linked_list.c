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

void display(NODEPTR head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
}

NODEPTR reverse(NODEPTR head)
{
    if (head->next == NULL)
        return head;
    NODEPTR newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    NODEPTR head = NULL;
    int input;
    enum Option
    {
        QUIT,
        ADD,
        REVERSE,
        DISPLAY
    };
    do
    {
        printf("Enter your option:\n");
        printf("0: Quit\n");
        printf("1: Add element\n");
        printf("2: Reverse\n");
        printf("3: Display\n");
        scanf("%d", &input);
        if (input == ADD)
        {
            int val;
            printf("Enter the value: ");
            scanf("%d", &val);
            insertAtHead(&head, val);
        } else if (input == REVERSE)
        {
            head = reverse(head);
        } else if (input == DISPLAY)
        {
            display(head);
        } else if (input == QUIT)
        {
            printf("Thanks\n");
            break;
        } else
        {
            printf("Invalid input");
        }
    } while (1);

    while (head != NULL)
    {
        NODEPTR toRemove = head;
        head = head->next;
        freeNode(head);
    }
    return 0;
}