#include <stdio.h>
int helper(int arr[], int n, int x)
{
    if (n == 0)
        return 0;
    if (arr[n - 1] == x) {
        return 1 + helper(arr, n - 1, x);
    }
    return helper(arr, n - 1, x);
}

int countElem(int arr[], int n, int elem) {
    if (n==0) {
        return 0;
    }
    int count = countElem(arr+1, n-1, elem);
    if (arr[0] == elem) {
        return 1+count;
    }
    return count;
}

int main()
{
    int arr[10] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 8};
    printf("%d\n", countElem(arr, 10, 2));
}