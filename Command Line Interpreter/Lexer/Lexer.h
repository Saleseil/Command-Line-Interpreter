#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <vector>

enum TokenType {
	Word,
	QuoteWord,
	Pipe,
	InputRedirect,
	OutputRedirect,
	AppendRedirect
};

struct Token {
	TokenType type;
	std::string value;
};

class CommandLine;

class Lexer {
public:

	//  Constuctor. Create the Lexer.
	Lexer(CommandLine* commandLine);

	//  Destroy the current lexer.
	~Lexer();

	//  Create tokens which send to parser.
	virtual void createTokens(const std::string& input);

	//  Returns the array of tokens.
	virtual std::vector<Token>* getTokens();

private:

	//  Pointer to the command line.
	CommandLine* commandLine;

	//  Array of tokens.
	std::vector<Token>* tokens;

};

inline std::vector<Token>* Lexer::getTokens() {
	return tokens;
}


#endif