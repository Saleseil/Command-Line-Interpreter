#ifndef TOUCH_H
#define TOUCH_H
#include "Command.h"

//  A command that create a file with specific name. 

class Touch : public Command {
public:

	Touch(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	virtual void execute();

	//  Redefined.
	virtual void inputFlow();	

	//  Redefined. No option for this command.
	virtual void outputFlow();

};

inline void Touch::outputFlow() {}

#endif

