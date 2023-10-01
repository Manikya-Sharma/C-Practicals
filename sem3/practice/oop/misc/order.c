#include <stdlib.h>

void *ret_mem()
{
    int *a = (int *)malloc(sizeof(int));
    return a;
}

int main() { int *p = ret_mem(); }