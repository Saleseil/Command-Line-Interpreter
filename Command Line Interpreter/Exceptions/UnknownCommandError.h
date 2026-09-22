#ifndef UNKNOWNCOMMANDERROR_H
#define UNKNOWNCOMMANDERROR_H
#include "ErrorCommandLine.h"

class UnknownCommandError : public ErrorCommandLine {
public:

	UnknownCommandError(CommandLine* commandLine, const std::string& name);

	virtual void updateMessage();
	
	virtual void processError();

private:

	std::string name;

};


#endif
