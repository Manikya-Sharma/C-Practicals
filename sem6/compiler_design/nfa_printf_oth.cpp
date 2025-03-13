#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TOKEN_VAR = 0;
const int TOKEN_PLUS = 1;
const int TOKEN_LPAREN = 2;
const int TOKEN_RPAREN = 3;
const int TOKEN_STRING = 4;
const int TOKEN_WHITESPACE = 5;
const int TOKEN_COMMA = 6;
const int TOKEN_SEMICOLON = 7;

inline bool valid(char ch) {
    return ch == '_' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

inline bool digit(char ch) {
    return ch >= '0' && ch <= '9';
}

inline bool ws(char ch) {
    return ch == ' ' || ch == '\n';
}

int variable(const string& input, size_t& lexeme_begin) {
    size_t i = lexeme_begin;
    if (valid(input[i])) {
        i++;
        while (valid(input[i]) || digit(input[i])) {
            i++;
        }
        lexeme_begin = i;
        return TOKEN_VAR;
    }
    return -1;
}

int addition(const string& input, size_t& lexeme_begin) {
    if (input[lexeme_begin] == '+') {
        lexeme_begin++;
        return TOKEN_PLUS;
    }
    return -1;
}

int paren(const string& input, size_t& lexeme_begin) {
    if (input[lexeme_begin] == '(') {
        lexeme_begin++;
        return TOKEN_LPAREN;
    } else if (input[lexeme_begin] == ')') {
        lexeme_begin++;
        return TOKEN_RPAREN;
    }
    return -1;
}

int str(const string& input, size_t& lexeme_begin, vector<size_t>& literals) {
    if (input[lexeme_begin] == '"') {
        size_t i = lexeme_begin + 1;
        while (i < input.length() && input[i] != '"') {
            i++;
        }
        literals.push_back(lexeme_begin + 1);
        lexeme_begin = i + 1;
        return TOKEN_STRING;
    }
    return -1;
}

int whitespace(const string& input, size_t& lexeme_begin) {
    if (ws(input[lexeme_begin])) {
        while (ws(input[++lexeme_begin]))
            ;
        return TOKEN_WHITESPACE;
    }
    return -1;
}

int punc(const string& input, size_t& lexeme_begin) {
    if (input[lexeme_begin] == ',') {
        lexeme_begin++;
        return TOKEN_COMMA;
    } else if (input[lexeme_begin] == ';') {
        lexeme_begin++;
        return TOKEN_SEMICOLON;
    }
    return -1;
}

void solve(const string& input, vector<int>& tokens, vector<size_t>& literals) {
    size_t lexeme_begin = 0;
    while (lexeme_begin < input.length()) {
        int token = variable(input, lexeme_begin);
        if (token != -1) {
            tokens.push_back(token);
            continue;
        }
        token = addition(input, lexeme_begin);
        if (token != -1) {
            tokens.push_back(token);
            continue;
        }
        token = paren(input, lexeme_begin);
        if (token != -1) {
            tokens.push_back(token);
            continue;
        }
        token = str(input, lexeme_begin, literals);
        if (token != -1) {
            tokens.push_back(token);
            continue;
        }
        token = whitespace(input, lexeme_begin);
        if (token != -1) {
            continue;
        }
        token = punc(input, lexeme_begin);
        if (token != -1) {
            tokens.push_back(token);
            continue;
        }
        cerr << "UNKOWN CHARACTER" << endl;
        exit(EXIT_FAILURE);
    }
}

void display(int token, const vector<size_t>& literals, const string& input,
             size_t& var_count, size_t& lit_count) {
    if (token == TOKEN_VAR) {
        cout << "<id," << var_count++ << ">";
    } else if (token == TOKEN_PLUS) {
        cout << "<+>";
    } else if (token == TOKEN_LPAREN) {
        cout << "<paren,s_op>";
    } else if (token == TOKEN_RPAREN) {
        cout << "<paren,s_cl>";
    } else if (token == TOKEN_STRING) {
        size_t start = literals[lit_count++];
        size_t end = input.find('"', start);
        cout << "<literal, \"" << input.substr(start, end - start) << "\">";
    } else if (token == TOKEN_COMMA) {
        cout << "<punc,>";
    } else if (token == TOKEN_SEMICOLON) {
        cout << "<punc,;>";
    }
}

int main() {
    string input = "printf( \"the addition of two number is %d\", a+b);";
    vector<int> tokens;
    vector<size_t> literals;

    solve(input, tokens, literals);

    cout << "Number of tokens: " << tokens.size() << endl;
    cout << "Tokens:-" << endl;

    size_t var_count = 0, lit_count = 0;
    for (const auto& token : tokens) {
        display(token, literals, input, var_count, lit_count);
        cout << endl;
    }

    return 0;
}
