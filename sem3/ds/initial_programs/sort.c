#include <stdio.h>
#define SIZE 100

void insertion_sort(int arr[], int size)
{
    int newArr[SIZE];
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            newArr[i] = arr[i];
            continue;
        }
        int j = i - 1;
        int elem = arr[i];
        while (newArr[j] > elem && j >= 0)
        {
            newArr[j + 1] = newArr[j];
            j--;
        }
        newArr[j + 1] = elem;
    }
    printf("Sorted Array:-\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", newArr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[SIZE];
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, size);
    return 0;
}