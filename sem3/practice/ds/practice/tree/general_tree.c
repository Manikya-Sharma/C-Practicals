#include <stdio.h>
#include <stdlib.h>
#define MAX_CHILDREN 10

struct Node
{
    int info;
    struct Node *children[MAX_CHILDREN];
};

typedef struct Node *NODEPTR;

NODEPTR getNode() { return (NODEPTR)malloc(sizeof(struct Node)); }

void freeNode(NODEPTR node) { free(node); }

NODEPTR makeTree(int info)
{
    NODEPTR root = getNode();
    root->info = info;
    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        root->children[i] = NULL;
    }
    return root;
}

void setNthChild(NODEPTR node, int info, int i)
{
    if (i >= MAX_CHILDREN)
    {
        printf("Invalid child insertion!");
        return;
    }
    node->children[i] = makeTree(info);
}

/* QUEUE for Level Order Traversal */
#define MAX_QUEUE 1000
struct queue
{
    NODEPTR items[MAX_QUEUE];
    int front, rear;
};
struct queue getQueue()
{
    struct queue q;
    q.front = -1;
    q.rear = 0;
    return q;
}
void insert(struct queue *pq, NODEPTR item) { pq->items[++pq->front] = item; }
NODEPTR remove_q(struct queue *pq) { return pq->items[pq->rear++]; }
int empty(struct queue *pq) { return pq->front < pq->rear; }

/* Level Order Traversal */
void levelOrderTraversal(NODEPTR root)
{
    struct queue q = getQueue();
    insert(&q, root);
    while (!empty(&q))
    {
        NODEPTR node = remove_q(&q);
        if (node == NULL)
            continue;
        printf("%d ", node->info);
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            insert(&q, node->children[i]);
        }
        freeNode(node); // we can no longer use the tree
    }
    printf("\n");
}

int main()
{

    NODEPTR root = makeTree(5);

    root->children[0] = makeTree(7);
    root->children[1] = makeTree(15);
    root->children[5] = makeTree(2);

    root->children[0]->children[0] = makeTree(13);
    root->children[5]->children[3] = makeTree(12);

    levelOrderTraversal(root);

    return 0;
}