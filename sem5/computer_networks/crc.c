#include <stdio.h>
#define MAX_SIZE 100

int main() {
    char gen[MAX_SIZE], data[MAX_SIZE];
    printf("Enter the generator sequence:");
    scanf("%s", gen);
    printf("Enter the data to be transmitted:");
    scanf("%s", data);

    // find the size of resulting output
    int genSize = 0;
    while (gen[genSize] != 0)
        genSize++;

    int dataSize = 0;
    while (data[dataSize] != 0)
        dataSize++;

    char result[dataSize + genSize];
    for (int i = 0; i < dataSize; i++) {
        result[i] = data[i];
    }
    for (int i = 0; i < genSize - 1; i++) {
        result[i + dataSize] = '0';
    }
    result[dataSize + genSize - 1] = 0;

    // perform division operation using xor
    char window[genSize];
    for (int i = 0; i < genSize; i++) {
        window[i] = data[i];
    }
    // `j` is the next bit to be inserted while dividing
    int j = genSize;
    while (j < dataSize + genSize) {
        for (int i = j - genSize; i < j; i++) {
            result[i] = (result[i] - '0') ^ (gen[i - j + genSize] - '0') + '0';
        }
        int i = j - genSize;
        while (i < dataSize && result[i] == '0') {
            i++;
            j++;
        }
    }
    // now last genSize-1 bits in result are to be added in original data
    char ans[dataSize + genSize];
    for (int i = 0; i < dataSize; i++) {
        ans[i] = data[i];
    }
    for (int i = 0; i < genSize; i++) {
        ans[dataSize + i] = result[dataSize + i];
    }
    ans[dataSize + genSize - 1] = 0;
    printf("Data to be sent: %s\n", ans);
    return 0;
}
