#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
struct
{
    int info;
    int used;

} NODES[MAX_NODES];
int makeTree(int root)
{
    NODES[0].info = root;
    NODES[0].used = 1;
    for (int i = 1; i < MAX_NODES; i++)
    {
        NODES[i].used = 0;
    }
    return 0;
}
void setLeft(int node, int info)
{
    NODES[2 * node + 1].info = info;
    NODES[2 * node + 1].used = 1;
}
void setRight(int node, int info)
{
    NODES[2 * node + 2].info = info;
    NODES[2 * node + 2].used = 1;
}

int left(int node) { return 2 * node + 1; }
int right(int node) { return 2 * node + 2; }
void display()
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        if (NODES[i].used == 0)
            continue;
        printf("%d ", NODES[i].info);
    }
    printf("\n");
}
void preorderDisplay(int root)
{
    if (NODES[root].used == 0)
    {
        return;
    }
    printf("%d ", NODES[root].info);
    preorderDisplay(left(root));
    preorderDisplay(right(root));
}
int main()
{
    /*

            5
           / \
          7  9
         /\   \
        11 12  14

     */
    int root = makeTree(5);
    setLeft(root, 7);
    setRight(root, 9);
    setLeft(left(root), 11);
    setRight(left(root), 12);
    setRight(right(root), 14);
    display();
    preorderDisplay(0);
    printf("\n");
    return 0;
}