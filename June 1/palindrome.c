#include <stdio.h>
int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s", str);

    // length
    int len = 0;
    while (str[len] != 0)
    {
        len++;
    }

    // check palindrome
    int i = 0, j = len - 1, flag = 0;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            flag = 1;
            break;
        }
        i++;
        j--;
    }
    if (flag)
        printf("Not a palindrome\n");
    else
        printf("Palindrome\n");
    return 0;
}