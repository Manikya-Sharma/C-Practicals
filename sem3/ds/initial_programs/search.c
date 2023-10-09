#define SIZE 100
#include <stdio.h>

int binarySearch(int arr[], int size, int elem)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] < elem)
        {
            low = mid + 1;
        } else if (arr[mid] > elem)
        {
            high = mid - 1;
        } else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int arr[SIZE], size, elem;
    printf("Enter the size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &elem);

    int found = binarySearch(arr, size, elem);
    if (found == -1)
    {
        printf("Element not found\n");
    } else
    {
        printf("Element found at index %d\n", found);
    }

    return 0;
}