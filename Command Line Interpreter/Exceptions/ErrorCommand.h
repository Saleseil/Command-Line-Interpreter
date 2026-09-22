#ifndef EXCEPTIONCOMMAND_H
#define EXCEPTIONCOMMAND_H
#include "ErrorMessage.h"

// Represents exceptions and errors that are captured for all commands.

class Command;


class ErrorCommand : public ErrorMessage{
public:

	ErrorCommand(Command* command);

protected:

	//  Pointer to command where the error occured.
	Command* command;

};
inline ErrorCommand::ErrorCommand(Command* command) : command(command){}



#endif
