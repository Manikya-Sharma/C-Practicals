#include <stdio.h>

int main()
{
    int n, item, res = -1;
    printf("size?");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i = i + 1)
    {
        scanf("%d", &arr[i]);
    }
    printf("Item to search?");
    scanf("%d", &item);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
            res = i;
    }
    printf("The index of %d in array is %d\n", item, res);
    return 0;
}