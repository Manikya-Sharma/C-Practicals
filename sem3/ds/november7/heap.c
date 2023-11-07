#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

struct Heap
{
    int items[HEAP_SIZE];
    int end;
};

void heapify(struct Heap *ph)
{
    for (int i = 0; i < ph->end; i++)
    {
        for (int j = i + 1; j <= ph->end; j++)
        {
            if (ph->items[i] > ph->items[j])
            {
                int temp = ph->items[i];
                ph->items[i] = ph->items[j];
                ph->items[j] = temp;
            }
        }
    }
}

void addToHeap(struct Heap *ph, int item)
{
    ph->items[++ph->end] = item;
    heapify(ph);
}

int removeFromHeap(struct Heap *ph)
{
    int item = ph->items[ph->end--];
    heapify(ph);
    return item;
}

void printHeap(struct Heap *ph)
{
    for (int i = 0; i <= ph->end; i++)
    {
        printf("%d ", ph->items[i]);
    }
    printf("\n");
}

int main()
{

    struct Heap h;
    h.end = -1;

    int option, item;
    do
    {
        printf("\n0. Quit \n");
        printf("1. Enter an element \n");
        printf("2. Remove an element \n");
        printf("3. Print heap\n");
        scanf("%d", &option);

        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element: ");
            scanf("%d", &item);
            addToHeap(&h, item);
        } else if (option == 2)
        {
            item = removeFromHeap(&h);
            printf("Removed %d from heap\n", item);
        } else if (option == 3)
        {
            printHeap(&h);
        }
    } while (option != 0);

    return 0;
}
