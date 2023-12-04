#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100

struct Node
{
    int info;
    int occupied;
};

struct Heap
{
    struct Node items[MAX_HEAP];
};

void swap(struct Node *n1, struct Node *n2)
{
    struct Node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

struct Heap getHeap()
{
    struct Heap h;
    for (int i = 0; i < MAX_HEAP; i++)
    {
        h.items[i].occupied = 0;
    }
    return h;
}

int parent(int idx)
{
    if (idx == 0)
        return -1;
    if (idx % 2 == 0)
        return (idx - 2) / 2;
    else
        return (idx - 1) / 2;
}

int left(int idx) { return 2 * idx + 1; }

int right(int idx) { return 2 * idx + 2; }

void insertHeap(struct Heap *ph, int item)
{
    int i = 0;
    while (ph->items[i].occupied != 0)
        i++;
    ph->items[i].info = item;
    ph->items[i].occupied = 1;
    // heapify
    int par = parent(i);
    while (par >= 0)
    {
        if (ph->items[par].info < item)
        {
            swap(&ph->items[par], &ph->items[i]);
            i = par;
            par = parent(par);
        } else
        {
            break;
        }
    }
}

void print(struct Heap *ph)
{
    for (int i = 0; i < MAX_HEAP; i++)
    {
        if (ph->items[i].occupied == 0)
        {
            break;
        }
        printf("%d ", ph->items[i].info);
    }
    printf("\n");
}

int removeElem(struct Heap *ph)
{
    int i = 0;
    while (ph->items[i].occupied == 1)
    {
        i++;
    }
    if (i-- == 0)
    {
        return -1; // no element
    }
    swap(&ph->items[i], &ph->items[0]);
    ph->items[i].occupied = 0; // remove from heap
    int removed = ph->items[i].info;

    // heapify
    i = 0;
    while (ph->items[i].occupied != 0)
    {
        int l = left(i);
        int r = right(i);
        int max;
        if (ph->items[l].occupied == 0)
        {
            break;
        } else if (ph->items[r].occupied == 0)
        {
            max = l;
        } else
        {
            if (ph->items[l].info > ph->items[r].info)
            {
                max = l;
            } else
            {
                max = r;
            }
        }

        if (ph->items[max].info > ph->items[i].info)
        {
            swap(&ph->items[max], &ph->items[i]);
            i = max;
        } else
        {
            break;
        }
    }
    return removed;
}

void heapSort(int *arr, int size)
{
    struct Heap h = getHeap();
    for (int i = 0; i < size; i++)
    {
        insertHeap(&h, arr[i]);
    }
    for (int j = 0; j < size; j++)
    {
        arr[j] = removeElem(&h);
    }
}

int main()
{

    struct Heap h = getHeap();
    int option;
    int elem;
    do
    {
        printf("\n0. Exit\n");
        printf("1. Enter an element\n");
        printf("2. Print the heap\n");
        printf("3. Remove an element\n");
        printf("4. Sort an array\n");
        scanf("%d", &option);
        if (option == 0)
        {
            printf("Bye\n");
        } else if (option == 1)
        {
            printf("Enter the element:");
            scanf("%d", &elem);
            insertHeap(&h, elem);
        } else if (option == 2)
        {
            print(&h);
        } else if (option == 3)
        {
            elem = removeElem(&h);
            printf("Removed %d\n", elem);
        } else if (option == 4)
        {
            printf("Enter the number of elements:");
            scanf("%d", &elem);
            int *arr = (int *)malloc(elem * sizeof(int));
            for (int i = 0; i < elem; i++)
            {
                int item;
                printf("Enter element %d: ", i + 1);
                scanf("%d", &item);
                arr[i] = item;
            }

            heapSort(arr, elem);
            printf("Sorted array:-\n");
            for (int i = 0; i < elem; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    } while (option != 0);
    return 0;
}
