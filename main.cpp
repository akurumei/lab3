#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>
#include <algorithm>

enum TokenType {
    KEYWORD, IDENTIFIER, NUMBER, SYMBOL, STRING, COMMENT, END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
};

const std::vector<std::string> keywords = {
    "def", "end", "if", "else", "while", "do", "true", "false", "nil", "class", "begin", "require"
};

const std::string symbols = "+-*/=(){}[],@";

class Lexer {
public:
    Lexer(const std::string& input) : input(input), pos(0), length(input.length()) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        while (pos < length) {
            char current = input[pos];
            if (isspace(current)) {
                pos++;
            } else if (isalpha(current) || current == '_') {
                tokens.push_back(lexIdentifier());
            } else if (isdigit(current)) {
                tokens.push_back(lexNumber());
            } else if (symbols.find(current) != std::string::npos) {
                tokens.push_back(lexSymbol());
            } else if (current == '\"') {
                tokens.push_back(lexString());
            } else if (current == '#') {
                tokens.push_back(lexComment());
            } else {
                std::cerr << "Unknown character: " << current << " at position " << pos << std::endl;
                pos++;
            }
        }
        tokens.push_back({END_OF_FILE, ""});
        return tokens;
    }

private:
    std::string input;
    size_t pos;
    size_t length;

    Token lexIdentifier() {
        size_t start = pos;
        while (pos < length && (isalnum(input[pos]) || input[pos] == '_')) {
            pos++;
        }
        std::string value = input.substr(start, pos - start);
        TokenType type = (std::find(keywords.begin(), keywords.end(), value) != keywords.end()) ? KEYWORD : IDENTIFIER;
        return {type, value};
    }

    Token lexNumber() {
        size_t start = pos;
        while (pos < length && isdigit(input[pos])) {
            pos++;
        }
        return {NUMBER, input.substr(start, pos - start)};
    }

    Token lexSymbol() {
        return {SYMBOL, std::string(1, input[pos++])};
    }

    Token lexString() {
        pos++; // Skip the opening quote
        size_t start = pos;
        while (pos < length && input[pos] != '\"') {
            pos++;
        }
        std::string value = input.substr(start, pos - start);
        pos++; // Skip the closing quote
        return {STRING, value};
    }

    Token lexComment() {
        size_t start = pos;
        while (pos < length && input[pos] != '\n') {
            pos++;
        }
        return {COMMENT, input.substr(start, pos - start)};
    }
};

int main() {
    std::ifstream file("Test1.rb");
    if (!file.is_open()) {
        std::cerr << "Failed to open file Test1.rb" << std::endl;
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    Lexer lexer(code);
    std::vector<Token> tokens = lexer.tokenize();

    for (const Token& token : tokens) {
        std::string type_str;
        switch (token.type) {
            case KEYWORD: type_str = "KEYWORD"; break;
            case IDENTIFIER: type_str = "IDENTIFIER"; break;
            case NUMBER: type_str = "NUMBER"; break;
            case SYMBOL: type_str = "SYMBOL"; break;
            case STRING: type_str = "STRING"; break;
            case COMMENT: type_str = "COMMENT"; break;
            case END_OF_FILE: type_str = "END_OF_FILE"; break;
        }
        std::cout << "<" << token.value << ", " << type_str << ">" << std::endl;
    }

    return 0;
}
