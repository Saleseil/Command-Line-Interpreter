#ifndef ECHO_H
#define ECHO_H
#include "Command.h"

//  A command that prints the text from console or from input file.

class Echo : public Command{
public:

	Echo(const std::string& name, CommandLine* commLine);

	virtual void execute();
	
	virtual void checkCommand();

};


#endif
