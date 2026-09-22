#ifndef TRUNCATE_H
#define TRUNCATE_H
#include "Command.h"

//  A command that clear the entire contents of the file. 

class Truncate : public Command {
public:

	//  Constructor.
	Truncate(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	virtual void execute();

	//  Redefined.
	virtual void inputFlow();
	
	//  Redefined. No output flow for this command.
	virtual void outputFlow();

};

inline void Truncate::outputFlow() {}

#endif