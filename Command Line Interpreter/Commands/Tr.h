#ifndef TR_H
#define TR_H
#include "Command.h"

//  A command that replace one substring to another substring.

class Tr : public Command{
public:

	Tr(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	//  Redefined.
	virtual void inputFlow();

	virtual void execute();

protected:

	//  Finding a 'what' and a 'with' arguments if there are exist.
	virtual void setWhatandWith(std::string& what, std::string& with);

	//  Helper method for finding 'what' and 'with' arguments.
	virtual void setInPipe(std::string& what, std::string& with);

	//  Helper method for finding 'what' and 'with' arguments.
	virtual void setWithoutPipe(std::string& what, std::string& with);

};

#endif
