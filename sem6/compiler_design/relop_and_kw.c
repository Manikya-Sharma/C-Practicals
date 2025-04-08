#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

// the types of tokens available
typedef enum {
    VARIABLE,
    NUMBER,
    L_PAREN,
    R_PAREN,
    WHILE,
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

TokenType nfa_while(char input[], int* lexeme_begin) {
    int state = 0;
    int i = *lexeme_begin;
    while (state != -1) {
        switch (state) {
            case 0: {
                if (input[i] == 'w') {
                    i++;
                    state = 1;
                } else {
                    state = -1;
                }
                break;
            }
            case 1: {
                if (input[i] == 'h') {
                    i++;
                    state = 2;
                } else {
                    state = -1;
                }
                break;
            }
            case 2: {
                if (input[i] == 'i') {
                    i++;
                    state = 3;
                } else {
                    state = -1;
                }
                break;
            }
            case 3: {
                if (input[i] == 'l') {
                    i++;
                    state = 4;
                } else {
                    state = -1;
                }
                break;
            }
            case 4: {
                if (input[i] == 'e') {
                    i++;
                    state = 5;
                } else {
                    state = -1;
                }
                break;
            }
            case 5: {
                if (is_variable_char(input[i]) || is_digit(input[i])) {
                    state = -1;
                } else {
                    *lexeme_begin = i;
                    return WHILE;
                }
            }
        }
    }
    return UNMATCH;
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
    int i = *lexeme_begin;
    if (input[i] == '=') {
        i++;
        if (input[i] == '=') {
            i++;
            *lexeme_begin = i;
            return RELOP_EQ;
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
                *lexeme_begin = i + 1;
                return NUMBER;
            }
        }
    }
    return UNMATCH;
}

TokenType nfa_paren(char input[], int* lexeme_begin) {
    int i = *lexeme_begin;
    if (input[i] == '(') {
        *lexeme_begin = i + 1;
        return L_PAREN;
    } else if (input[i] == ')') {
        *lexeme_begin = i + 1;
        return R_PAREN;
    } else {
        return UNMATCH;
    }
}

void lexical_analyzer(char input[], TokenType tokens[], int* token_count,
                      int literals[], int* lit_count) {
    int lexeme_begin = 0;
    while (input[lexeme_begin] != 0) {
        TokenType token;
        token = nfa_while(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*token_count] = token;
            *token_count = *token_count + 1;
            continue;
        }
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
        token = nfa_paren(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*token_count] = token;
            *token_count = *token_count + 1;
            continue;
        printf("Unexpected token\n");
        exit(1);
    }
}

void display(TokenType token, int literals[], char input[], int* lit_count) {
    static int count = 0;
    switch (token) {
        case WHILE:
            printf("<while>");
            break;
        case L_PAREN:
            printf("<paren, S_OP>");
            break;
        case R_PAREN:
            printf("<paren, S_CL>");
            break;
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
        case RELOP_EQ:
            printf("<relop,EQ>");
            break;
        case UNMATCH:
            break;
    }
}

int main() {
    char input[MAX_LEN] = "while(abc==32)";

    TokenType tokens[MAX_LEN];
    int literals[MAX_LEN];
    int token_count = 0, literal_count = 0;
    lexical_analyzer(input, tokens, &token_count, literals, &literal_count);

    int count = 0;
    for (int i = 0; i < token_count; i++) {
        display(tokens[i], literals, input, &count);
    }
    printf("\n");

    return 0;
}
