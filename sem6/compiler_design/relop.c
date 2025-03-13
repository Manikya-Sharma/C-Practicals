#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

typedef enum { GT, LT, GE, LE, NE, EQ } ATTR;
typedef enum { RELOP } TOKEN_TYPE;

typedef struct {
    TOKEN_TYPE type;
    ATTR attribute;
} TOKEN;

TOKEN new(TOKEN_TYPE type) {
    TOKEN token;
    token.type = type;
    return token;
}

int idx = 0;
char c, input[MAX_LEN];
void retract() {
    idx--;
}
void fail() {
    printf("Not a relop\n");
    exit(1);
}
char nextChar() {
    return input[idx++];
}

TOKEN getRelop() {
    int state = 0;
    TOKEN retToken = new (RELOP);
    while (1) {
        switch (state) {
            case 0:
                c = nextChar();
                if (c == '<') {
                    state = 1;
                } else if (c == '=') {
                    state = 5;
                } else if (c == '>') {
                    state = 6;
                } else {
                    fail();
                }
                break;
            case 1:
                c = nextChar();
                if (c == '=') {
                    state = 2;
                } else if (c == '>') {
                    state = 3;
                } else {
                    state = 4;
                }
                break;
            case 2:
                retToken.attribute = LE;
                return retToken;
            case 3:
                retToken.attribute = NE;
                return retToken;
            case 4:
                retract();
                retToken.attribute = LT;
                return retToken;
            case 5:
                retToken.attribute = EQ;
                return retToken;
            case 6:
                c = nextChar();
                if (c == '=') {
                    state = 7;
                } else {
                    state = 8;
                }
                break;
            case 7:
                retToken.attribute = GE;
                return retToken;
            case 8:
                retract();
                retToken.attribute = GT;
                return retToken;
        }
    }
}

void display(ATTR attr) {
    switch (attr) {
        case GT:
            printf("GT\n");
            break;
        case LT:
            printf("LT\n");
            break;
        case EQ:
            printf("EQ\n");
            break;
        case NE:
            printf("NE\n");
            break;
        case GE:
            printf("GE\n");
            break;
        case LE:
            printf("LE\n");
            break;
    }
}

int main() {
    printf("Enter input:");
    scanf("%s", input);

    TOKEN token = getRelop();
    display(token.attribute);

    return 0;
}
