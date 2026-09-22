#include "Lexer.h"
#include "../Exceptions/LexicalError.h"
#include "../CommandLine/CommandLine.h"

Lexer::Lexer(CommandLine* commLine) : commandLine(commLine) {
    tokens = new std::vector<Token>();
}

Lexer::~Lexer() {
    delete tokens;
}

void Lexer::createTokens(const std::string& input) {
    for (size_t i = 0; i < input.size();){
        char c = input[i];
        if (std::isspace(c)){
            i++;
            continue;
        }
        if (c == '|'){
            tokens->push_back({ TokenType::Pipe, "|" });
            i++;
            continue;
        }
        if (c == '<')
        {
            tokens->push_back({ TokenType::InputRedirect, "<" });
            i++;
            continue;
        }
        if (c == '>')
        {
            if (i + 1 < input.size() && input[i + 1] == '>'){
                tokens->push_back({ TokenType::AppendRedirect, ">>" });
                i += 2;
            }
            else{
                tokens->push_back({ TokenType::OutputRedirect, ">" });
                i++;
            }
            continue;
        }
      
        if (c == '"'){
            i++;
            std::string value;
            value.push_back('"');
            while (i < input.size() && input[i] != '"')
            {
                value += input[i];
                i++;
            }
            if (i == input.size()) throw new LexicalError(commandLine, "Lexical error: Unterminated quoted string");
            i++;
            value.push_back('"');
            tokens->push_back({TokenType::QuoteWord,value});
            continue;
        }
        std::string value;
        while (i < input.size()){
            char ch = input[i];
            if (std::isspace(ch) ||
                ch == '|' ||
                ch == '<' ||
                ch == '>' ||
                ch == '"'){
                break;
            }
            value += ch;
            i++;
        }
        tokens->push_back({TokenType::Word,value});
    } 
}