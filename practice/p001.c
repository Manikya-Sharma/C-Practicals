// prime number
#include<stdio.h>

int main()
{
    int num, i=2;
    printf("Please enter a number: ");
    scanf("%d", &num);
    char prime = 'y';
    while (i*i<=num)
    {
        if (num%i == 0){
            prime = 'n';
            break;
        }
        i++;
    }
    if (prime == 'y')
    {
        printf("%d is a prime number", num);
    }
    else
    {
        printf("%d is not a prime number since %d is one of its factor", num, i);
    }
    return 0;
}
