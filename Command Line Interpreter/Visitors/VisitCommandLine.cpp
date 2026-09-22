#include "VisitCommandLine.h"
#include "../CommandLine/CommandLine.h"
#include "../Exceptions/LexicalError.h"
#include "../Exceptions/UnknownCommandError.h"
#include "../Lexer/Lexer.h"

VisitCommandLine::VisitCommandLine(CommandLine* commandLine, const std::vector<Token>* tokens) : commandLine(commandLine), tokens(tokens) {};

VisitCommandLine::~VisitCommandLine() {}

void VisitCommandLine::proccesException() {
	if (!tokens) return;
	for (size_t i = 0; i < tokens->size(); i++) {
		if ((*tokens)[i].type == Pipe) {
			checkTokensWithPipe();
			return;
		}
	}
	checkTokensWithoutPipe();
}

void VisitCommandLine::checkNameSyntax(Token token) {
	if (token.type != Word) {
		throw new LexicalError(commandLine, "Lexical error: Incorrect command name: " + token.value);
	}
	for (size_t i = 0; i < token.value.length(); i++) {
		if(token.value[i] == '-') throw new LexicalError(commandLine, "Lexical error: Incorrect command name: " + token.value);
	}
}

bool VisitCommandLine::isMorePipesExists(size_t position) {
	if (!tokens) return false;
	if (position >= tokens->size()) return false;
	for (size_t pos = position; pos < tokens->size(); pos++) {
		if ((*tokens)[pos].type == Pipe) return true;
	}
	return false;
}

void VisitCommandLine::checkTokensWithPipe() {
	if (!tokens) return;
	size_t index = 0;
	std::string position = "start";
	size_t numInputRed = 0;
	size_t numOutRed = 0;
	bool isRedOut = false;
	bool isRedIn = false;
	while (index < tokens->size()) {
		if ((*tokens)[index].type == QuoteWord) {
			index++;
			continue;
		}
		checkInvalidCharacters((*tokens)[index].value);
		if (!index) checkNameSyntax((*tokens)[index]);
		if ((*tokens)[index].type == Word && (*tokens)[index].value[0] == '-' && !((*tokens)[index].value.length() - 1)) {
			throw new LexicalError(commandLine, "Lexical error: Option argument has zero characters!");
		}
		if ((*tokens)[index].type == Pipe) {
			index++;
			if (!isMorePipesExists(index + 1)) position = "end";
			else position = "mid";
			if (index >= tokens->size()) {
				throw new LexicalError(commandLine, "Lexical error: Incorrect pipe: " + (*tokens)[index-1].value);
			}
			checkNameSyntax((*tokens)[index]);
			continue;
		}
		if (position == "start") {
			if ((*tokens)[index].type == OutputRedirect || (*tokens)[index].type == AppendRedirect) {
				throw new LexicalError(commandLine, "Lexical error: First command can't have output redirections!");
			}
			if ((*tokens)[index].type == InputRedirect) {
				isRedIn = true;
				index++;
				if (index >= tokens->size()) {
					throw new LexicalError(commandLine, "Lexical error: Invalid last argument redirection: " + (*tokens)[index - 1].value);
				}
				if (numInputRed > 0) {
					throw new LexicalError(commandLine, "Lexical error: Number of input redirections can't be greater then 1");
				}
				numInputRed++;
				if ((*tokens)[index].type != Word || (*tokens)[index].value[0] == '-') {
					throw new LexicalError(commandLine, "Lexical error: Invalid next argument to redirections: " + (*tokens)[index].value);
				}
				checkInvalidCharacters((*tokens)[index].value);
				index++;
				continue;
			}
			if (isRedIn) {
				throw new LexicalError(commandLine, "Lexical error: Input redirections must be the last arguments in first command!");
			}
		}
		if (position == "mid") {
			if ((*tokens)[index].type == OutputRedirect || (*tokens)[index].type == AppendRedirect || (*tokens)[index].type == InputRedirect) {
				throw new LexicalError(commandLine, "Lexical error: Miidle commands can't have input or output redirections!");
			}
		}
		if (position == "end") {
			if ((*tokens)[index].type == InputRedirect) {
				throw new LexicalError(commandLine, "Lexical error: Last command can't have input redirection!");
			}
			if ((*tokens)[index].type == OutputRedirect || (*tokens)[index].type == AppendRedirect) {
				if (numOutRed > 0) {
					throw new LexicalError(commandLine, "Lexical error: Number of output redirections can't be greater then 1!");
				}
				numOutRed++;
				isRedOut = true;
				index++;
				if (index >= tokens->size()) {
					throw new LexicalError(commandLine, "Lexical error: Invalid last argument redirection: " + (*tokens)[index - 1].value);
				}
				if ((*tokens)[index].type != Word || (*tokens)[index].value[0] == '-') {
					throw new LexicalError(commandLine, "Lexical error: Invalid next argument to redirections: " + (*tokens)[index].value);
				}
				checkInvalidCharacters((*tokens)[index].value);
				index++;
				continue;
			}
			if (isRedOut) {
				throw new LexicalError(commandLine, "Lexical error: Output redirections must be the last arguments in last command!");
			}
		}
		index++;
	}
}

void VisitCommandLine::checkTokensWithoutPipe() {
	if (!tokens) return;
	checkRedirections();
	for (size_t i = 0; i < tokens->size(); i++) {
		if ((*tokens)[i].type == QuoteWord) continue;
		checkInvalidCharacters((*tokens)[i].value);
		if ((*tokens)[i].type == Word && (*tokens)[i].value[0] == '-' && !((*tokens)[i].value.length()-1)) {
			throw new LexicalError(commandLine, "Lexical error: Option argument has zero characters!");
		}
		if (i == 0) {
			checkNameSyntax((*tokens)[i]);
			continue;
		}
	}
}

bool VisitCommandLine::isRedirectionsExists() {
	if (!tokens) return false;
	for (size_t i = 0; i < tokens->size(); i++) {
		if ((*tokens)[i].type == AppendRedirect || (*tokens)[i].type == InputRedirect || (*tokens)[i].type == OutputRedirect) return true;
	}
	return false;
}

void VisitCommandLine::checkRedirections() {
	if (!tokens) return;
	if (!isRedirectionsExists()) return;
	size_t index = 0;
	size_t inputRedirections = 0;
	size_t outRedirections = 0;
	bool isRed = false;
	while (index < tokens->size()) {
		if ((*tokens)[index].type == InputRedirect || (*tokens)[index].type == OutputRedirect || (*tokens)[index].type == AppendRedirect) {
			if ((*tokens)[index].type == InputRedirect) {
				if (inputRedirections > 0) {
					throw new LexicalError(commandLine, "Lexical error: Number of input redirections can't be greater then 1!");
				}
				inputRedirections++;
			}
			if ((*tokens)[index].type == OutputRedirect || (*tokens)[index].type == AppendRedirect) {
				if (outRedirections > 0) {
					throw new LexicalError(commandLine, "Lexical error: Number of output redirections can't be greater then 1!");
				}
				outRedirections++;
			}
			index++;
			if (index >= tokens->size()) {
				throw new LexicalError(commandLine, "Lexical error: Invalid last argument redirection: " + (*tokens)[index-1].value);
			}
			if ((*tokens)[index].type != Word || (*tokens)[index].value[0]=='-') {
				throw new LexicalError(commandLine, "Lexical error: Invalid next argument to redirections: " + (*tokens)[index].value);
			}
			isRed = true;
			index++;
			continue;
		}
		if (isRed) throw new LexicalError(commandLine, "Lexical error: Redirections must be the last arguments!");
		index++;
	}
}

void VisitCommandLine::checkCommandName(const std::string& commandName) {
	size_t i = 0;
	while (i < AllCommands.size()) {
		if (commandName == AllCommands[i]) return;
		i++;
	}
	throw new UnknownCommandError(commandLine, commandName);
}

void VisitCommandLine::checkInvalidCharacters(const std::string& word) {
	for (size_t i = 0; i < word.length(); i++) {
		for (size_t j = 0; j < 17; j++) {
			if (word[i] == characters[j]) throw new LexicalError(commandLine, "Lexical error: Incorrect argument: " + word);
		}
	}
}