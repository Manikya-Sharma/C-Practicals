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

    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < nc; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}