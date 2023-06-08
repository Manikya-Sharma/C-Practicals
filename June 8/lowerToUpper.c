#include <stdio.h>

int main()
{
    char s1[20];
    scanf("%s", s1);
    int len = 0;
    while (s1[len] != 0)
    {
        len++;
    }
    for (int i = 0; i < len; i++)
    {
        if (s1[i] > 'a' && s1[i] < 'z')
        {
            s1[i] -= 32;
        }
    }
    printf("%s\n", s1);
    return 0;
}