#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int size)
{
    int new_arr[size];

    for (int i = 0; i < size; i++) {
        int elem = arr[i];
        int j = i;
        while (j > 0) {
            if (new_arr[j - 1] > elem) {
                new_arr[j] = new_arr[j - 1];
                j--;
            }
            else {
                break;
            }
        }
        new_arr[j] = elem;
    }
    printArray(new_arr, 5);
}
int main()
{
    int arr[5] = {4, 1, 2, 3, 5};
    printArray(arr, 5);
    insertion_sort(arr, 5);
}