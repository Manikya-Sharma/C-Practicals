// lcm of a two numbers

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int lcm(int num1, int num2)
{
    if (num1 == 1)
    {
        return num2;
    }
    if (num2 == 1)
    {
        return num1;
    }
    if (num1 == 0 || num2 == 0)
    {
        return 0;
    }
    if (num1 % num2 == 0 || num2 % num1 == 0)
    {
        return max(num1, num2);
    }
    if (num1 > num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    int i = num2;
    while (i % num1 != 0 || i % num2 != 0)
    {
        i += 1;
    }
    return i;
}
int main()
{
    int num1, num2, ans;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    ans = lcm(num1, num2);
    printf("lcm of %d and %d is %d", num1, num2, ans);
    return 0;
}