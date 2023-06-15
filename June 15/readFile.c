#include <stdio.h>

int main()
{
    FILE *fptr = fopen("myfile.txt", "r");
    if (fptr == NULL)
    {
        printf("No such file exists!");
        return 0;
    }
    while (1)
    {
        char ch = fgetc(fptr);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }
    printf("\n");
}