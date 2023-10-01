#include <stdio.h>

#define MAXQUEUE 100

struct queue {
    int front, rear;
    int items[MAXQUEUE];
};

int empty(struct queue *q)
{
    if (q->rear < q->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct queue *q, int item)
{
    if (q->rear == MAXQUEUE - 1) {
        printf("Overflow!\n");
    }
    q->items[++q->rear] = item;
}

int remove_q(struct queue *q)
{
    if (empty(q)) {
        printf("Underflow!\n");
    }
    return q->items[q->front++];
}

void print_q(struct queue *q)
{
    printf("%d", q->items[q->front]);
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf(", %d", q->items[i]);
    }
    printf("\n");
}

int main()
{
    struct queue q;
    q.front = 0;
    q.rear = -1;
    int stop_execution = 0;
    printf("Enter operation:\n");
    printf("1. Enter element\n");
    printf("2. Remove element\n");
    printf("3. Print queue\n");
    printf("4. Quit\n");
    char input;
    int elem;
    while (!stop_execution) {
        printf("> ");
        scanf("%c", &input);
        switch (input) {
        case '1':
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(&q, elem);
            break;
        case '2':
            elem = remove_q(&q);
            printf("Removed %d", elem);
            break;
        case '3':
            print_q(&q);
            break;
        case '4':
            printf("Thank you\n");
            stop_execution = 1;
        }
    }
    return 0;
}