#include <stdio.h>
#include <string.h>
int main()
{
    char s[20];
    gets(s);
    char new_s[20];
    int len = 0;
    while (s[len] != 0)
    {
        len++;
    }
    int j = len;
    int t = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ' || i == 0)
        {
            for (int x = i == 0 ? i : i + 1; x < j; x++)
            {
                new_s[t] = s[x];
                t++;
            }
            new_s[t] = ' ';
            j = i;
            t++;
        }
    }
    printf("%s\n", new_s);
    return 0;
}