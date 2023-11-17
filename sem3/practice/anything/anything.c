#include <stdio.h>

int calculate(char *s)
{
    int arr[300000];

    int j = 0, i = 0;
    int next_neg = 1;
    while (s[i] != 0)
    {
        if (s[i] == '+' || s[i] == '(' || s[i] == ')' || s[i] == ' ')
        {
            i++;
            continue;
        }
        if (s[i] == '-')
        {
            next_neg = -next_neg;
        } else
        {
            if (s[i + 1] >= '0' && s[i + 1] <= '9')
            {
                int to_add = s[i] - '0';
                while (s[i + 1] >= '0' && s[i + 1] <= '9')
                {
                    i++;
                    to_add = to_add * 10 + (s[i] - '0');
                }
                arr[j++] = to_add;
                continue;
            }
            arr[j++] = next_neg * (s[i] - '0');
            next_neg = 1;
        }
        i++;
    }
    int result = 0;
    for (int i = 0; i < j; i++)
    {
        result += arr[i];
    }
    return result;
}

int main()
{
    char s[] = "2147483647";
    printf("\n%d\n\n", calculate(s));
    return 0;
}