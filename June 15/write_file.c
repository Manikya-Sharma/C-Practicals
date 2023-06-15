#include <stdio.h>
#include <string.h>

int main()
{
    char myPara[100];
    FILE *fptr = fopen("myfile.txt", "w");
    gets(myPara);
    fprintf(fptr, "%s", myPara);
    fclose(fptr);
    return 0;
}