#include <stdio.h>
#define MAX_LEN 20

int nfa(char input[]) {
    int state = 0;
    for (int i = 0; input[i]; i++) {
        switch (state) {
            case 13: {
                if (state == 13) {
                    return 0;
                }
            }
            case 12: {
                if (state == 12) {
                    if (input[i] == 'c') {
                        state = 13;
                    } else if (state == 12) {
                        state = -1;
                    }
                }
            }
            case 11: {
                if (state == 11) {
                    if (input[i] == 'i') {
                        state = 12;
                    } else if (state == 11) {
                        state = -1;
                    }
                }
            }
            case 10: {
                if (state == 10) {
                    if (input[i] == 't') {
                        state = 11;
                    } else if (state == 10) {
                        state = -1;
                    }
                }
            }
            case 9: {
                if (state == 9) {
                    if (input[i] == 's') {
                        state = 10;
                    } else if (state == 9) {
                        state = -1;
                    }
                }
            }
            case 8: {
                if (state == 8) {
                    if (input[i] == 'i') {
                        state = 9;
                    } else if (state == 8) {
                        state = -1;
                    }
                }
            }
            case 7: {
                if (state == 7) {
                    if (input[i] == 'n') {
                        state = 8;
                    } else if (state == 7) {
                        state = -1;
                    }
                }
            }
            case 6: {
                if (state == 6) {
                    if (input[i] == 'i') {
                        state = 7;
                    } else if (state == 6) {
                        state = -1;
                    }
                }
            }
            case 5: {
                if (state == 5) {
                    if (input[i] == 'm') {
                        state = 6;
                    } else if (state == 5) {
                        state = -1;
                    }
                }
            }
            case 4: {
                if (state == 4) {
                    if (input[i] == 'r') {
                        state = 5;
                    } else if (state == 4) {
                        state = -1;
                    }
                }
            }
            case 3: {
                if (state == 3) {
                    if (input[i] == 'e') {
                        state = 4;
                    } else if (state == 3) {
                        state = -1;
                    }
                }
            }
            case 2: {
                if (state == 2) {
                    if (input[i] == 't') {
                        state = 3;
                    } else if (state == 2) {
                        state = -1;
                    }
                }
            }
            case 1: {
                if (state == 1) {
                    if (input[i] == 'e') {
                        state = 2;
                    } else if (state == 1) {
                        state = -1;
                    }
                }
            }
            case 0: {
                if (state == 0) {
                    if (input[i] == 'd') {
                        state = 1;
                    } else if (state == 0) {
                        state = -1;
                    }
                }
            }
        }
    }
    return state == 13;
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
