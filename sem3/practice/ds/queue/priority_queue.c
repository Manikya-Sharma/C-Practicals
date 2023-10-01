#include <stdio.h>

#define MAXQUEUE 100

struct priority_queue {
    int front, rear;
    int items[MAXQUEUE];
};

int empty(struct priority_queue *pq)
{
    if (pq->rear < pq->front) {
        return 1;
    }
    else {
        return 0;
    }
}

void insert(struct priority_queue *pq, int item)
{
    if (pq->rear == MAXQUEUE - 1) {
        printf("Overflow!\n");
    }
    pq->items[++pq->rear] = item;
}

int remove_q(struct priority_queue *pq)
{
    int min_idx = pq->front;
    for (int i = pq->front; i < pq->rear; i++) {
        if (pq->items[i] < pq->items[min_idx]) {
            min_idx = i;
        }
    }
    int min_elem = pq->items[min_idx];
    for (int i = min_idx; i < pq->rear; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    pq->rear--;
    return min_elem;
}

void print_q(struct priority_queue *pq)
{
    printf("%d", pq->items[pq->front]);
    for (int i = pq->front + 1; i <= pq->rear; i++) {
        printf(", %d", pq->items[i]);
    }
    printf("\n");
}

int main()
{

    struct priority_queue q;
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