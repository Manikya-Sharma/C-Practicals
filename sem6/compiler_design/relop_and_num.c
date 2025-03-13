#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

// the types of tokens available
typedef enum {
    VARIABLE,
    WHITE_SPACE,
    NUMBER,
    RELOP_GE,
    RELOP_GT,
    RELOP_LE,
    RELOP_LT,
    RELOP_NE,
    RELOP_EQ,
    UNMATCH
} TokenType;

// helper functions
int is_variable_char(char ch) {
    return ch == '_' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}
int is_white_space(char ch) {
    return ch == ' ' || ch == '\n';
}

TokenType nfa_var(char input[], int* lexeme_begin) {
    int i = *lexeme_begin;
    int state = 0;
    if (is_variable_char(input[i])) {
        state = 1;
        i++;
    }
    if (state == 1) {
        while (is_variable_char(input[i]) || is_digit(input[i])) {
            i++;
        }
        *lexeme_begin = i;
        return VARIABLE;
    } else {
        return UNMATCH;
    }
}

TokenType nfa_relop(char input[], int* lexeme_begin) {
    int state = 0;
    int i = *lexeme_begin;
    while (state != -1) {
        switch (state) {
            case 0: {
                if (input[i] == '<') {
                    state = 1;
                    i++;
                } else if (input[i] == '>') {
                    state = 4;
                    i++;
                } else if (input[i] == '=') {
                    state = 7;
                    i++;
                } else {
                    state = -1;
                }
                break;
            }
            case 1: {
                if (input[i] == '=') {
                    i++;
                    state = 2;
                } else {
                    i++;
                    state = 3;
                }
                break;
            }
            case 2: {
                *lexeme_begin = i;
                return RELOP_LE;
            }
            case 3: {
                *lexeme_begin = i - 1;
                return RELOP_LT;
            }
            case 4: {
                if (input[i] == '=') {
                    state = 5;
                    i++;
                } else {
                    state = 6;
                    i++;
                }
                break;
            }
            case 5: {
                *lexeme_begin = i;
                return RELOP_GE;
            }
            case 6: {
                *lexeme_begin = i - 1;
                return RELOP_GT;
            }
            case 7: {
                if (input[i] == '=') {
                    state = 8;
                    i++;
                } else {
                    // single '=' is not a relop
                    return UNMATCH;
                }
                break;
            }
            case 8: {
                *lexeme_begin = i;
                return RELOP_EQ;
            }
        }
    }
    return UNMATCH;
}

TokenType nfa_number(char input[], int* lexeme_begin, int literals[],
                     int* lit_count) {
    int state = 0;
    int i = *lexeme_begin;
    while (state != -1) {
        switch (state) {
            case 0: {
                if (is_digit(input[i])) {
                    i++;
                    state = 1;
                } else {
                    state = -1;
                }
                break;
            }
            case 1: {
                if (is_digit(input[i])) {
                    i++;
                    state = 1;
                } else {
                    state = 2;
                }
            }
            case 2: {
                literals[*lit_count] = *lexeme_begin;
                *lit_count = *lit_count + 1;
                *lexeme_begin = i;
                return NUMBER;
            }
        }
    }
    return UNMATCH;
}

void lexical_analyzer(char input[], TokenType tokens[], int* token_count,
                      int literals[], int* lit_count) {
    int lexeme_begin = 0;
    while (input[lexeme_begin] != 0) {
        TokenType token;
        token = nfa_var(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*token_count] = token;
            *token_count = *token_count + 1;
            continue;
        }
        token = nfa_relop(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*token_count] = token;
            *token_count = *token_count + 1;
            continue;
        }
        token = nfa_number(input, &lexeme_begin, literals, lit_count);
        if (token != UNMATCH) {
            tokens[*token_count] = token;
            *token_count = *token_count + 1;
            continue;
        }
        printf("Unexpected token\n");
        exit(1);
    }
}

void display(TokenType token, int literals[], char input[], int* lit_count) {
    static int count = 0;
    switch (token) {
        case VARIABLE:
            printf("<id,%d>", count++);
            break;
        case NUMBER: {
            printf("<num,");
            int start = literals[*lit_count];
            *lit_count = *lit_count + 1;
            while (is_digit(input[start])) {
                printf("%c", input[start]);
                start++;
            }
            printf(">");
            break;
        }
        case RELOP_LE:
            printf("<relop,LE>");
            break;
        case RELOP_LT:
            printf("<relop,LT>");
            break;
        case RELOP_GE:
            printf("<relop,GE>");
            break;
        case RELOP_GT:
            printf("<relop,GT>");
            break;
        case RELOP_EQ:
            printf("<relop,EQ>");
            break;
        case RELOP_NE:
            printf("<relop,NE>");
            break;
        case WHITE_SPACE:
        case UNMATCH:
            break;
    }
}

int main() {
    printf("Enter the number of cases:");
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        char input[MAX_LEN];
        scanf("%s", input);
        printf("Input: %s\n", input);
        TokenType tokens[MAX_LEN];
        int literals[MAX_LEN];
        int lit_count = 0;
        int token_count = 0;
        lexical_analyzer(input, tokens, &token_count, literals, &lit_count);
        int count = 0;
        for (int i = 0; i < token_count; i++) {
            display(tokens[i], literals, input, &count);
        }
        printf("\n");
    }
    return 0;
}
