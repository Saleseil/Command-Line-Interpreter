#ifndef PROMPT_H
#define PROMPT_H
#include "Command.h"

//  A command that sets a different command prompt in the cosnole.

class Prompt : public Command{
public:

	Prompt(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	virtual void execute();

	//  Redefined.
	virtual void inputFlow();

	//  Redefines. No output flow for this command.  
	virtual void outputFlow();

};

inline void Prompt::outputFlow() {}


#endif

