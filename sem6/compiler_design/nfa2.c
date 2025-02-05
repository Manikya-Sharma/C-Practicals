#include <stdio.h>
#define MAX_LEN 20

int nfa(char input[]) {
    int idx = 0;
    int state = 0;
    switch (state) {
        case 0: {
            if (input[idx] == 'd') {
                idx++;
                state = 1;
            } else {
                state = -1;
            }
        }
        case 1: {
            if (input[idx] == 'e') {
                idx++;
                state = 2;
            } else {
                state = -1;
            }
        }
        case 2: {
            if (input[idx] == 't') {
                idx++;
                state = 3;
            } else {
                state = -1;
            }
        }
        case 3: {
            if (input[idx] == 'e') {
                idx++;
                state = 4;
            } else {
                state = -1;
            }
        }
        case 4: {
            if (input[idx] == 'r') {
                idx++;
                state = 5;
            } else {
                state = -1;
            }
        }
        case 5: {
            if (input[idx] == 'm') {
                idx++;
                state = 6;
            } else {
                state = -1;
            }
        }
        case 6: {
            if (input[idx] == 'i') {
                idx++;
                state = 7;
            } else {
                state = -1;
            }
        }
        case 7: {
            if (input[idx] == 'n') {
                idx++;
                state = 8;
            } else {
                state = -1;
            }
        }
        case 8: {
            if (input[idx] == 'i') {
                idx++;
                state = 9;
            } else {
                state = -1;
            }
        }
        case 9: {
            if (input[idx] == 's') {
                idx++;
                state = 10;
            } else {
                state = -1;
            }
        }
        case 10: {
            if (input[idx] == 't') {
                idx++;
                state = 11;
            } else {
                state = -1;
            }
        }
        case 11: {
            if (input[idx] == 'i') {
                idx++;
                state = 12;
            } else {
                state = -1;
            }
        }
        case 12: {
            if (input[idx] == 'c') {
                idx++;
                state = 13;
            } else {
                state = -1;
            }
        }
    }
    return state == 13 && input[idx] == 0;
}

int main() {
    char inp[MAX_LEN];
    printf("Enter the string:");
    scanf("%s", inp);
    int result = nfa(inp);
    if (result) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
