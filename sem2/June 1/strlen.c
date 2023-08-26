#include <stdio.h>

int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s", str);
    int len = 0;
    while (str[len] != 0)
    {
        len++;
    }
    printf("The length of string is %d\n", len);
    return 0;
}