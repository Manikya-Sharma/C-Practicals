#include<stdio.h>
int main()
{
    int r1, c1, r2, c2;
    printf("Rows and Columns of matrix 1?");
    scanf("%d %d", &r1, &c1);
    printf("Rows and Columns of matrix 2?");
    scanf("%d %d", &r2, &c2);
    int arr1[r1][c1], arr2[r2][c2], result[r1][c2];
    printf("Matrix 1\n");

    // input of matrix 1
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Matrix 2\n");

    // input of matrix 2
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    // setting up result
    for (int i=0; i<r1; i++){
        for (int j=0; j<c2; j++){
            result[i][j] = 0;
            for (int k=0; k<c1; k++){
                result[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }

    // printing the Matrix
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}