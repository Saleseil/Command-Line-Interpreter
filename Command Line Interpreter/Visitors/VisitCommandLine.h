#ifndef VISITCOMMANDLINE_H
#define VISITCOMMANDLINE_H
#include "Visitor.h"
#include <vector>
#include <string>

struct Token;

//  Visitor that applies all command lines.

class CommandLine;

class VisitCommandLine : public Visitor {
public:

	// Constructor.
	VisitCommandLine(CommandLine* commandLine, const std::vector<Token>* tokens);

	// Destroy the visitor for command line.
	~VisitCommandLine();

	//  Find the lexical errors and update information line.
	virtual void proccesException();

	//  Is this command can be executed?
	virtual void checkCommandName(const std::string& commandName);

	//  Check if tokens are regular with pipe.
	virtual void checkTokensWithPipe();

	//  Check if tokens are regular without pipe.
	virtual void checkTokensWithoutPipe();

protected:

	//  Check if there is forbidden characters in command line.
	virtual void checkInvalidCharacters(const std::string& word);

	//  Check lexical rules for redirections.
	virtual void checkRedirections();

	//  Check if redirections exists.
	virtual bool isRedirectionsExists();

	//  Check if more pipes exists from current posistion.
	virtual bool isMorePipesExists(size_t position);

	//  Check command name 
	virtual void checkNameSyntax(Token token);
private:

	//  Pointer to command line.
	CommandLine* commandLine;

	//  List of all commands that can be executed.
	std::vector<std::string> AllCommands = { "echo", "prompt", "touch", "time", "date", "truncate", "rm", "wc", "tr", "head", "batch"};

	//  List of forbidden characters.
	char characters[17] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '?', ',', '\'', ';', '\\', ':'};

	//  Lexer tokens.
	const std::vector<Token>* tokens;
};



#endif 
