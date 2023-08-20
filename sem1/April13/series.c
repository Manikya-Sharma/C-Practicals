#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int N1, N2, i=1;
    scanf("%d", &N1);
    scanf("%d", &N2);
    while (i <= N1)
    {
        int term = (3*i)+5;
        if (term % N2 != 0)
        {
            printf("%d\n", term);
        } else {
            N1++;
        }
        i++;
    }
    return 0;
}