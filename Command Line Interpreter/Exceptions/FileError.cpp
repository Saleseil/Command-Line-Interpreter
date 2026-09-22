#include "FileError.h"
#include "../Commands/Command.h"

FileError::FileError(const std::string& message, Command* command) : ErrorCommand(command) {
	setMessage(message);
}

void FileError::processError() {
	command->setErrorLine(getMessage());
}