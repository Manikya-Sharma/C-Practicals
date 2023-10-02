#include <stdio.h>
int findRepeat(int arr[], int size)
{
    int sum = 0, _xor = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        _xor ^= arr[i];
    }
    return (sum - _xor);
}

int main()
{
    int arr[5] = {1, 2, 2, 5, 4};
    printf("%d\n", findRepeat(arr, 5));
    return 0;
}