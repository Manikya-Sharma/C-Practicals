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
    for (int i = n - 1; i >= 0; i = i - 1)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}