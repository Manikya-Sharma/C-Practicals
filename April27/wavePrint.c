#include <stdio.h>
int main()
{
    int nr, nc;
    printf("Rows and columns?");
    scanf("%d %d", &nr, &nc);
    int arr[nr][nc];
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < nc; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < nr; j++)
            {
                printf("%d", arr[j][i]);
            }
        }
        else
        {
            for (int j = nr - 1; j >= 0; j--)
            {
                printf("%d", arr[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}