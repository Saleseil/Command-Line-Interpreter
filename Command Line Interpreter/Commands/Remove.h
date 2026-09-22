#ifndef REMOVE_H
#define REMOVE_H
#include "Command.h"

//  A command that removes a file.

class Remove : public Command {
public:

	Remove(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	virtual void execute();

	//  Redefined.
	virtual void inputFlow();

	//  Redefined. No output flow for this command. 
	virtual void outputFlow();

};

inline void Remove::outputFlow() {}

#endif