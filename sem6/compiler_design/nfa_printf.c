#include <stdio.h>
#include <stdlib.h>

// Max number of tokens
#define MAX_LEN 1000

// the types of tokens available
typedef enum {
    VARIABLE,
    ARITHMETIC_PL,
    L_PARENTHESIS,
    R_PARENTHESIS,
    STRING,
    WHITE_SPACE,
    COMMA,
    SEMICOLON,
    ERROR,
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
        if (i == *lexeme_begin) {
            // empty variable means invalid character was found
            return ERROR;
        }
        *lexeme_begin = i;
        return VARIABLE;
    } else {
        return UNMATCH;
    }
}

TokenType nfa_arith_add(char input[], int* lexeme_begin) {
    if (input[*lexeme_begin] == '+') {
        *lexeme_begin = *lexeme_begin + 1;
        return ARITHMETIC_PL;
    } else {
        return UNMATCH;
    }
}

TokenType nfa_parenthesis(char input[], int* lexeme_begin) {
    if (input[*lexeme_begin] == '(') {
        *lexeme_begin = *lexeme_begin + 1;
        return L_PARENTHESIS;
    } else if (input[*lexeme_begin] == ')') {
        *lexeme_begin = *lexeme_begin + 1;
        return R_PARENTHESIS;
    } else {
        return UNMATCH;
    }
}

TokenType nfa_string(char input[], int* lexeme_begin, int literals[],
                     int* literal_count) {
    if (input[*lexeme_begin] == '"') {
        int i = *(lexeme_begin) + 1;
        while (input[i] != 0 && input[i] != '"') {
            i++;
        }
        if (input[i] == 0) {
            // unterminated string
            return ERROR;
        }
        literals[*literal_count] = *lexeme_begin + 1;
        *literal_count = *literal_count + 1;
        *lexeme_begin = i + 1;
        return STRING;
    } else {
        return UNMATCH;
    }
}

TokenType nfa_whitespace(char input[], int* lexeme_begin) {
    int state = 0;
    int i = *lexeme_begin;
    if (is_white_space(input[i])) {
        state = 1;
        i++;
        while (is_white_space(input[i])) {
            i++;
        }
        *lexeme_begin = i;
        return WHITE_SPACE;
    } else {
        return UNMATCH;
    }
}

TokenType nfa_punctuation(char input[], int* lexeme_begin) {
    if (input[*lexeme_begin] == ',') {
        *lexeme_begin = *lexeme_begin + 1;
        return COMMA;
    } else if (input[*lexeme_begin] == ';') {
        *lexeme_begin = *lexeme_begin + 1;
        return SEMICOLON;
    }
    return UNMATCH;
}

// The main function to perform lexical analysis of given input
void lexical_analysis(char input[], TokenType tokens[], int* count,
                      int literals[], int literal_count) {
    int lexeme_begin = 0;
    while (input[lexeme_begin] != 0) {
        TokenType token = nfa_var(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*count] = token;
            *count = *count + 1;
            continue;
        }
        if (token == ERROR)
            return;
        token = nfa_arith_add(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*count] = token;
            *count = *count + 1;
            continue;
        }
        if (token == ERROR)
            return;
        token = nfa_parenthesis(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*count] = token;
            *count = *count + 1;
            continue;
        }
        if (token == ERROR)
            return;
        token = nfa_string(input, &lexeme_begin, literals, &literal_count);
        if (token != UNMATCH) {
            tokens[*count] = token;
            *count = *count + 1;
            continue;
        }
        if (token == ERROR)
            return;
        token = nfa_whitespace(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*count] = token;
            *count = *count + 1;
            continue;
        }
        if (token == ERROR)
            return;
        token = nfa_punctuation(input, &lexeme_begin);
        if (token != UNMATCH) {
            tokens[*count] = token;
            *count = *count + 1;
            continue;
        }
        if (token == ERROR)
            return;
        // Nothing matched
        printf("Unkown token provided, terminating");
        exit(1);
    }
}

// Helper function to display tokens
void display(TokenType token, int literals[], char input[], int* var_count,
             int* lit_count) {
    switch (token) {
        case VARIABLE:
            printf("<id,%d>", *var_count);
            *var_count = *var_count + 1;
            break;
        case ARITHMETIC_PL:
            printf("<arith,PL>");
            break;
        case L_PARENTHESIS:
            printf("<paren, s_open>");
            break;
        case R_PARENTHESIS:
            printf("<paren, s_close>");
            break;
        case STRING: {
            int start = literals[*lit_count];
            *lit_count = *lit_count + 1;
            int end = start;
            char str[MAX_LEN];
            while (input[end] != '"') {
                str[end - start] = input[end];
                end++;
            }
            str[end - start] = 0;
            printf("<string, \"%s\">", str);
            break;
        }
        case COMMA:
            printf("<punc,COMMA>");
            break;
        case SEMICOLON:
            printf("<punc,SEMICOLON>");
            break;
        case WHITE_SPACE:
            printf("<whitespace>");
            break;
        case ERROR:
            printf("Error occured, terminating\n");
            exit(1);
        case UNMATCH:
            break;
    }
}

int main() {
    char input[MAX_LEN] =
        "printf(  \"the addition of two number is %d\", a+b);";

    TokenType tokens[MAX_LEN];
    int count = 0;
    // keep the position of beggining of string literals
    int literals[MAX_LEN];
    int literal_count = 0;

    lexical_analysis(input, tokens, &count, literals, literal_count);

    printf("Number of tokens: %d\n", count);
    printf("Tokens:-\n");
    int var_count = 0, lit_count = 0;
    for (int i = 0; i < count; i++) {
        display(tokens[i], literals, input, &var_count, &lit_count);
        printf("\n");
    }

    return 0;
}
