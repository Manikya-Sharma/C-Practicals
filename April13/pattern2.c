#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<2*n-1; i++){
        if (i>3){
            i = 6-i;
        }
        for (int j=0; j<i; j++){
            int temp = n-j;
            printf("%d", temp);
        }

        for (int k=0; k<(2*n)-(2*i); k++){
            int temp2 = n-1;
            printf("%d", temp2);
        }
        for (int m=n-i; m<i; m++){
            int temp3 = m+1;
            printf("%d", temp3);
        }
        printf("\n");
    }
}