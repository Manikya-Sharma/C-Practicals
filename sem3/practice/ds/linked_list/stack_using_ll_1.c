#include <stdio.h>
#include <stdlib.h>
#define NUMNODES 500

struct nodetype
{
    int info, next;
};

static struct nodetype node[NUMNODES];
static int avail = 0;

void initialize()
{
    for (int i = 0; i < NUMNODES - 1; i++)
    {
        node[i].next = i + 1;
    }
    node[NUMNODES - 1].next = -1;
}

int getnode()
{
    int p;
    if (avail == -1)
    {
        printf("Stack Overflow");
        exit(1);
    }
    p = avail;
    avail = node[avail].next;
    return p;
}

void freeNode(int p)
{
    node[p].next = avail;
    avail = p;
}

void push(int p, int val)
{
    int nextNode = getnode();
    node[p].next = nextNode;
    node[p].info = val;
}

int pop(int p)
{
    // TODO: Something's wrong
    int val = node[p].info;
    freeNode(p);
    return val;
}

int main()
{

    initialize();
    int top = getnode();
    int input;
    enum Option
    {
        ADD,
        REMOVE,
        EXIT
    };
    do
    {
        printf("Enter your option:\n");
        printf("1: Add element\n");
        printf("2: Remove elemet\n");
        printf("3: Exit\n");
        scanf("%d", &input);
        input--;
        if (input == ADD)
        {
            int val;
            printf("Enter the value: ");
            scanf("%d", &val);
            push(top, val);
        }
        else if (input == REMOVE)
        {
            int x = pop(top);
            printf("Removed: %d\n", x);
        }
        else if (input == EXIT)
        {
            printf("Thanks\n");

            break;
        }
        else
        {
            printf("Invalid input");
        }
    } while (1);
}
