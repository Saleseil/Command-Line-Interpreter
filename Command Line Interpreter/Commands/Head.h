#ifndef HEAD_H
#define HEAD_H
#include "Command.h"

//  A command that prints the first 'n' lines in the output of command. 

class Head : public Command {
public:

	//  Constructor.
	Head(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	//  Redefined.
	virtual void inputFlow();

	virtual void execute();

};

#endif 

