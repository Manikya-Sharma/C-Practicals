#include <stdio.h>

int main()
{
    char s1[20];
    char s2[20];
    scanf("%s", s1);
    scanf("%s", s2);

    int i = 0;
    while (s1[i] == s2[i])
    {
        if (s1[i] == '\0' && s2[i] == '\0')
        {
            break;
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        printf("Equal");
    else
        printf("Not equal");
    return 0;
}