/*
if array is [2,4,6,1]
output:
    *
    *
  * *
  * *
* * *
* * * *
*/

#include <stdio.h>
int main()
{
    int n, temp;
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

    // printing the pattern
    temp = max;
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp <= arr[j])
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
        temp = temp - 1;
    }
    return 0;
}