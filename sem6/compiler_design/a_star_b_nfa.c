#include <stdio.h>
#define MAX_LEN 30

int nfa(char input[]) {
    int state = 0;
    for (int i = 0; input[i] != 0; i++) {
        if (state == 0 && input[i] == 'a') {
            state = 0;
        } else if (state == 0 && input[i] == 'b') {
            state = 1;
        } else {
            state = -1;
        }
    }
    return (state == 1);
}

int main() {
    int test_cases;
    printf("Number of testcases?: ");
    scanf("%d", &test_cases);
    while (test_cases--) {
        char input[MAX_LEN];
        printf("Enter the string:");
        scanf("%s", input);
        if (nfa(input)) {
            printf("Accepted\n");
        } else {
            printf("Rejected\n");
        }
    }
    return 0;
}
