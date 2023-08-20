#include<stdio.h>

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

    for (int count = 0; count < n-1; count++)
    {
        int min_idx=count;
        for (int j = count+1; j < n; j++)
        {
            if (arr[min_idx]>arr[j])
            {
                min_idx=j;
            }
        }
        int temp = arr[count];
        arr[count] = arr[min_idx];
        arr[min_idx] = temp;
    }


    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}