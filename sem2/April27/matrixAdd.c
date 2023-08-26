#include <stdio.h>
int main()
{
    int nr, nc;
    printf("Rows and Columns?");
    scanf("%d %d", &nr, &nc);
    int arr1[nr][nc], arr2[nr][nc], arr3[nr][nc];
    printf("Array 1\n");
    // input of array 1
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Array 2\n");
    // input of array 2
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    // getting final array
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    // printing the array
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}