#include<stdio.h>
int main()
{
    int num, i=1, z;
    scanf("%d", &num);
    z = num;
    while (i<=(2*num-1))
    {
        int j=1;
        while (j<=(2*num-1))
        {
            if ((i==1 || i==2*num-1) || (j==1 || j==(2*num-1)))
            {
                printf("%d ", num);
            }
            else
            {
                z--;
                printf("%d ", z);
            }
            j += 1;
        }
        printf("\n");
        i += 1;
    }
    return 0;
}