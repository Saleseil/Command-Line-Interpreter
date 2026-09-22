#ifndef EXCEPTIONCOMMANDLINE_H
#define EXCEPTIONCOMMANDLINE_H
#include "ErrorMessage.h"

//  Represents exceptions and errors that are captured for command line.

class CommandLine;

class ErrorCommandLine : public ErrorMessage {
public:

	ErrorCommandLine(CommandLine* commandLine);

protected:

	CommandLine* commandLine;

};

inline ErrorCommandLine::ErrorCommandLine(CommandLine* commandLine) : commandLine(commandLine){}


#endif