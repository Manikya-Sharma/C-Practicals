#include <stdio.h>

void quick_sort(int arr[], int size)
{
    int pivot = size - 1;
    while (pivot > 0) {
        int j = 0;
        for (int i = 0; i < pivot; i++) {
            if (arr[i] > pivot) {
                j = i + 1;
            }
        }
        if (j == 0) {
            pivot--;
        }
        else {
            // swap arr[j-1] and arr[pivot]
            int temp = arr[j - 1];
            arr[j - 1] = arr[pivot];
            arr[pivot] = temp;
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[5] = {4, 1, 2, 3, 5};
    printArray(arr, 5);
    quick_sort(arr, 5);

    printArray(arr, 5);
}