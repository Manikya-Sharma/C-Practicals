#include <stdio.h>
int main()
{
    int n;
    printf("size?");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i = i + 1)
    {
        scanf("%d", &arr[i]);
    }
    // finding the maximum
    int max = arr[0];
    for (int i = 0; i <= n - 1; i = i + 1)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("The maximum number in array is %d\n", max);
    return 0;
}