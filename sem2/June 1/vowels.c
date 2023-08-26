#include <stdio.h>
int main()
{
    char str[20];
    printf("Enter the string: ");
    scanf("%s", str);
    int i = 0, count = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            count++;
        }
        i++;
    }
    printf("Given string has %d vowels\n", count);
    return 0;
}