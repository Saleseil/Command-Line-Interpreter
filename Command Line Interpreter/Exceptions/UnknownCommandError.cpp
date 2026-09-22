#include "UnknownCommandError.h"
#include "../CommandLine/CommandLine.h"

UnknownCommandError::UnknownCommandError(CommandLine* commandLine, const std::string& name) : ErrorCommandLine(commandLine), name(name) {
	updateMessage();
}

void UnknownCommandError::updateMessage() {
	std::string& mess = getMessage();
	mess += "Unknown command: " + name;
}


void UnknownCommandError::processError() {
	commandLine->setErrorLine(getMessage());
}