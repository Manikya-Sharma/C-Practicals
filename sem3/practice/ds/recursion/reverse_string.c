#include <stdio.h>
#include <stdlib.h>

char *concat(char *str1, char *str2, int len1, int len2)
{
    char *new_str = (char *)malloc((len1 + len2) * sizeof(char));
    for (int i = 0; i < len1; i++) {
        new_str[i] = str1[i];
    }
    int k = len1;
    for (int j = 0; j < len2; j++) {
        new_str[k] = str2[j];
        k++;
    }
    return new_str;
}

char *reverse_string(char *str, int size)
{
    if (size == 1) {
        return str;
    }
    else {
        return concat(&str[size - 1], reverse_string(str, size - 1), 1,
                      size - 1);
    }
}

int main()
{
    char *str = (char *)malloc(5 * sizeof(char));
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    char *reversed = reverse_string(str, 5);
    printf("%s\n", reversed);
}