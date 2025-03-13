#include <iostream>
#include <string>

using namespace std;

const int GT = 0;
const int LT = 1;
const int GE = 2;
const int LE = 3;
const int NE = 4;
const int EQ = 5;

enum Type { RELOP };

struct Token {
    Type type;
    int attribute;
};

Token newToken(Type type) {
    return {type};
}

void retract(size_t& i) {
    if (i > 0)
        i--;
}

void fail() {
    cout << "Not a relop" << endl;
    exit(EXIT_FAILURE);
}

char nextChar(const string& input, size_t& i) {
    return (i < input.length()) ? input[i++] : '\0';
}

Token solve(const string& input) {
    size_t i = 0;
    int state = 0;
    char c;
    Token retToken = newToken(RELOP);

    while (true) {
        switch (state) {
            case 0:
                c = nextChar(input, i);
                if (c == '<')
                    state = 1;
                else if (c == '=')
                    state = 5;
                else if (c == '>')
                    state = 6;
                else
                    fail();
                break;
            case 1:
                c = nextChar(input, i);
                if (c == '=')
                    state = 2;
                else if (c == '>')
                    state = 3;
                else
                    state = 4;
                break;
            case 2:
                retToken.attribute = LE;
                return retToken;
            case 3:
                retToken.attribute = NE;
                return retToken;
            case 4:
                retract(i);
                retToken.attribute = LT;
                return retToken;
            case 5:
                retToken.attribute = EQ;
                return retToken;
            case 6:
                c = nextChar(input, i);
                if (c == '=')
                    state = 7;
                else
                    state = 8;
                break;
            case 7:
                retToken.attribute = GE;
                return retToken;
            case 8:
                retract(i);
                retToken.attribute = GT;
                return retToken;
        }
    }
}

void print(int attr) {
    if (attr == GT)
        cout << "GT" << endl;
    else if (attr == LT)
        cout << "LT" << endl;
    else if (attr == EQ)
        cout << "EQ" << endl;
    else if (attr == NE)
        cout << "NE" << endl;
    else if (attr == GE)
        cout << "GE" << endl;
    else if (attr == LE)
        cout << "LE" << endl;
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    Token token = solve(input);
    print(token.attribute);

    return 0;
}
