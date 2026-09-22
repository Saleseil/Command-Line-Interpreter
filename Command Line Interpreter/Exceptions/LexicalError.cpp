#include "LexicalError.h"
#include "../CommandLine/CommandLine.h"
#include "../Visitors/VisitCommandLine.h"

LexicalError::LexicalError(CommandLine* commandLine, const std::string& errorMess) : ErrorCommandLine(commandLine) {
	setMessage(errorMess);
}

void LexicalError::processError() {
	commandLine->setErrorLine(getMessage());
}

void LexicalError::updateMessage() {};


