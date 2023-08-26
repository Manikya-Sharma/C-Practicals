#include <stdio.h>
int main()
{
    int n;
    printf("size?");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i = i + 1)
    {
        scanf("%d", &arr[i]);
    }
    // check palindrome
    int flag = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Not a palindrome\n");
    else
        printf("Palindrome\n");
    return 0;
}