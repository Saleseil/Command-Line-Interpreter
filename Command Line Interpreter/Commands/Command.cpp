#include "Command.h"
#include "../Stream/InputFileStream.h"
#include "../Stream/OutputFileStream.h"
#include "../Stream/ConsoleStream.h"
#include "../Visitors/VisitCommand.h"
#include "../CommandLine/CommandLine.h"

Command::Command(const std::string& commandName, CommandLine* commLine) : VisitCommand(nullptr), next(nullptr), clsStream(nullptr), inputFileStream(nullptr), outputFileStream(nullptr), name(commandName), commandLine(commLine){}

Command::~Command() {
	delete VisitCommand;
	delete inputFileStream;
	delete outputFileStream;
}

int Command::getnumOptArguments() {
	int optlen = 0;
	for (std::string arg : arguments) {
		if (arg[0] == '-') optlen++;
	}
	return optlen;
}

std::string* Command::getopt() {
	for (std::string& arg : arguments) {
		if (arg[0] == '-') return &arg;
	}
	return nullptr;
}

bool Command::checkoutredirection() {
	for (size_t i = 0; i < arguments.size(); i++) {
		if (arguments[i][0] == '>') return true;
	}
	return false;
}

void Command::inputFromConosle() {
	std::string& line = getinputline();
	clsStream = ConsoleStream::Insstance();
	line = clsStream->read();
}

void Command::inputFromQuotes(const std::string& argument) {
	size_t len = argument.length();
	std::string& line = getinputline();
	line = argument.substr(1, len - 2);
}

void Command::inputFromFile(const std::string& argument) {
	std::string& line = getinputline();
	inputFileStream = new InputFileStream(argument, this);
	line = inputFileStream->read();
}

void Command::outputInConsole(const std::string& line) {
	if (line.empty()) return;
	clsStream = ConsoleStream::Insstance();
	clsStream->print(line);
}

void Command::outputInFile(const std::string& argument) {
	std::string simbol;
	int k = 0;
	while (argument[k] == '>') {
		simbol += argument[k];
		k++;
	}
	outputFileStream = new OutputFileStream(argument, simbol, this);
	outputFileStream->print(getoutputline());
}

void Command::inputFlow() {
	std::vector<std::string>& args = getArguments();
	if (args.empty()) {
		inputFromConosle();
		return;
	}
	for (size_t i = 0; i < args.size(); i++) {
		if (args[i][0] == '<') {
			inputFromFile(args[i]);
			return;
		}
	}
	if (args[0][0] == '"') {
		inputFromQuotes(args[0]);
		return;
	}
	inputFromFile(args[0]);
}

void Command::outputFlow() {
	std::vector<std::string>& args = getArguments();
	for (size_t i = 0; i < args.size(); i++) {
		if (args[i][0] == '>') {
			outputInFile(args[i]);
			return;
		}
	}
	outputInConsole(outputline);
}

void Command::printError() {
	clsStream = ConsoleStream::Insstance();
	clsStream->print(getErrorLine());
}