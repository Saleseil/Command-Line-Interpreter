#include "SyntaxError.h"
#include "../Commands/Command.h"

SyntaxError::SyntaxError(const std::string& message, Command* command) : ErrorCommand(command) {
	setMessage(message);
}

void SyntaxError::processError() {
	command->setErrorLine(getMessage());
}
