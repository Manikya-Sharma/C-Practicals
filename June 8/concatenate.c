#include <stdio.h>

int main()
{
    char s1[20];
    char s2[20];
    scanf("%s", s1);
    scanf("%s", s2);
    int len = 0;
    while (s1[len] != '\0')
    {
        len++;
    }
    int i = len, j = 0;
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = s2[j];
    printf("%s\n", s1);
    return 0;
}
