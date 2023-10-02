#include <stdio.h>
int binary_search(int arr[], int size, int elem)
{
    int found = -1;
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] > elem) {
            end = mid - 1;
        }
        else if (arr[mid] < elem) {
            start = mid + 1;
        }
        else {
            found = mid;
            break;
        }
    }
    return found;
}

int binary_recursive(int arr[], int start, int end, int elem)
{
    int mid = (start + end) / 2;
    if (start > end) {
        return -1;
    }
    if (arr[mid] == elem) {
        return mid;
    }
    else if (arr[mid] > elem) {
        return binary_recursive(arr, start, mid - 1, elem);
    }
    else {
        return binary_recursive(arr, mid + 1, end, elem);
    }
}

int main()
{
    int arr[10] = {1, 3, 5, 6, 7, 10, 11, 15, 99, 100};
    int ind = binary_search(arr, 10, 6);
    int ind2 = binary_recursive(arr, 0, 10, 6);
    printf("%d, %d\n", ind, ind2);
    return 0;
}