#include<stdio.h>
int main()
{
    int n, i=2, count=0;
    printf("Enter the number:");
    scanf("%d",&n);
    while(i*i<=n){
        if (n%i == 0){
            count += 1;
            break;
        }
        i += 1;
    }
    if (count == 0){
        printf("%d is a prime number", n);
    } else {
        printf("%d is a not prime number", n);
    }
    return 0;
}