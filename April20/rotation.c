#include <stdio.h>
int main()
{
    int n, rot, temp;
    printf("size?");
    scanf("%d", &n);
    printf("Number of rotations?");
    scanf("%d", &rot);
    int arr[n];
    for (int i = 0; i <= n - 1; i = i + 1)
    {
        scanf("%d", &arr[i]);
    }
    for (int j = 1; j <= rot; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                temp = arr[i];
                arr[i] = arr[n - 1];
            }
            else
            {
                int temp2 = arr[i];
                arr[i] = temp;
                temp = temp2;
            }
        }
    }
    printf("Reversed array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}