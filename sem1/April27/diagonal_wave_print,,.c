#include <stdio.h>

int main()
{
    int m, n;
    printf("size?");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int newArr[m * n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int count = 0;
    int i = 0, j = 0, diag = 0;
    while (count < (m * n))
    {
        newArr[count] = arr[i][j];
        count++;
        if (diag % 2 != 0)
        {
            while (j > 0 && i < n - 1)
            {
                i++;
                j--;
                newArr[count] = arr[i][j];
                count++;
            }
        }
        else
        {
            while (i > 0 && j < m - 1)
            {
                i--;
                j++;
                newArr[count] = arr[i][j];
                count++;
            }
        }

        if (i == 0)
        {
            if (j != n - 1)
            {
                // not at top right corner
                j++;
            }
            else
            {
                i++;
            }
        }
        else if (j == 0)
        {
            if (i != m - 1)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        else if (i == n - 1)
        {
            j++;
        }
        else if (j == m - 1)
        {
            i++;
        }
        diag++;
    }
    count = 0;
    for (int i = 0; i < m * n; i++)
    {
        printf("%d ", newArr[i]);
        count++;
        if (count % n == 0)
        {
            printf("\n");
        }
    }
    return 0;
}