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

    for (int count = 1; count <= n - 1; count++)
    // 0th index already sorted
    {
        int item = arr[count];
        int j = count - 1;
        while (j >= 0 && arr[j] > item)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // no-shift => break
        arr[j + 1] = item;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}