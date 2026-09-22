#ifndef TIME_H
#define TIME_H
#include "Command.h"

//  A command that prints the latest current time.

class Time : public Command {
public:

	Time(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	virtual void execute();

	//  Redefined. No input flow for this command.
	virtual void inputFlow();

};

inline void Time::inputFlow() {}

#endif 

