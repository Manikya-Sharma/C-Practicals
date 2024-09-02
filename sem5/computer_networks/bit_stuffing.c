#include <stdio.h>
#define MAX_SIZE 100

int main() {
    // Take bit sequence as input
    char bit_sequence[MAX_SIZE];
    printf("Enter the bit sequence:");
    scanf("%s", bit_sequence);

    int n = 0;
    while (bit_sequence[n] != 0)
        n++;

    char result[MAX_SIZE];

    int i = 0, k = 0;
    while (i < n) {
        int one_count = 0;
        while (i < n && bit_sequence[i] == '1') {
            result[k++] = bit_sequence[i++];
            one_count++;
            if (one_count == 5) {
                one_count = 0;
                result[k++] = '0';
            }
        }
        if (i < n) {
            result[k++] = bit_sequence[i++];
        }
    }
    result[k] = 0;
    printf("Result: %s\n", result);
    return 0;
}
