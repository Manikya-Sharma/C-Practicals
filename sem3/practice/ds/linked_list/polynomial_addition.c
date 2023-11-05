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

void addTerm(int coeff, int degree, NODEPTR head)
{

    if (degree == 0)
    {
        head->info = coeff;
        return;
    }

    int i = 0;
    while (i < degree - 1)
    {
        head = head->next;
        i++;
    }

    NODEPTR newNode = getNode();
    newNode->info = coeff;

    newNode->next = head->next;
    head->next = newNode;
}

NODEPTR addPoly(NODEPTR poly1, NODEPTR poly2)
{
    NODEPTR head = getNode();
    head->info = poly1->info + poly2->info;
    poly1 = poly1->next;
    poly2 = poly2->next;
    NODEPTR newNode = head;

    while (poly1 != NULL && poly2 != NULL)
    {
        newNode->next = getNode();
        newNode = newNode->next;
        newNode->info = poly1->info + poly2->info;
        poly1 = poly1->next;
        poly2 = poly2->next;
    }

    while (poly1 != NULL)
    {
        newNode->next = getNode();
        newNode = newNode->next;
        newNode->info = poly1->info;
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        newNode->next = getNode();
        newNode = newNode->next;
        newNode->info = poly2->info;
        poly2 = poly2->next;
    }
    newNode->next = NULL;
    return head;
}

void displayPoly(NODEPTR node)
{
    if (node->next == NULL)
    {
        printf("%d ", node->info);
        return;
    }

    displayPoly(node->next);
    printf("%d ", node->info);
}

int main()
{
    NODEPTR poly1 = getNode();
    addTerm(3, 0, poly1);
    addTerm(4, 1, poly1);
    addTerm(7, 2, poly1);
    displayPoly(poly1);
    printf("\n");

    NODEPTR poly2 = getNode();
    addTerm(4, 0, poly2);
    addTerm(1, 1, poly2);
    addTerm(9, 2, poly2);
    displayPoly(poly2);
    printf("\n");

    NODEPTR sum = addPoly(poly1, poly2);
    displayPoly(sum);
    printf("\n");

    return 0;
}