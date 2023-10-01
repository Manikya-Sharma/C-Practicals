#include <stdio.h>
void toh(int num, char from, char to, char aux) {
    if (num == 1) {
        printf("Move disc from %c to %c\n", from, to);
        return;
    }
    toh(num-1, from, aux, to);
    printf("Move disc from %c to %c\n", from, to);
    toh(num-1, aux, to, from);
}

int main() {
    int num = 3;
    toh(num, 'A', 'C', 'B');
    return 0;
}