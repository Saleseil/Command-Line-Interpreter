#ifndef DATE_H
#define DATE_H
#include "Command.h"

//  A command that prints the latest current date.

class Date : public Command{
public:
	
	//  Constructor.
	Date(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();
	
	//  Redefined. No input flow for this command.
	virtual void inputFlow();

	//  Redefined.
	virtual void execute();

};

inline void Date::inputFlow() {}

#endif
