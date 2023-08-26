#include<stdio.h>
int main()
{
    int n, x=1, sum=0;
    printf("Enter the number of terms:");
    scanf("%d", &n);
    while(x <= n)
    {
        sum  = sum+x;
        x+=1;
    }
    printf("The sum is %d", sum);
    return 0;
}