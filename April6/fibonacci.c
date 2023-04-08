#include<stdio.h>
int main()
{
    int n, a=0, b=1;
    printf("Enter the nth term:");
    scanf("%d", &n);
    int i=0;
    while (i <= n)
    {
        printf("%d\n", a);
        int sum = a+b;
        a=b;
        b=sum;
        i++;
    }
    return 0;
}