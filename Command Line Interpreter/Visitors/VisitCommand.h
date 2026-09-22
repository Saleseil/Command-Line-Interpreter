#ifndef VISITCOMMAND_H
#define VISITCOMMAND_H
#include "Visitor.h"

//  Visitor that applies all commands in command line.

class Command;

class VisitCommand : public Visitor {
public:

	VisitCommand(Command* nameCommand);

protected:

	//  Returns the pointer of current command.
	virtual Command* getCommand();

private:

	//  Pointer to current command.
	Command* thisCommand;

};

inline VisitCommand::VisitCommand(Command* nameCommand) : thisCommand(nameCommand){}

inline Command* VisitCommand::getCommand() {
	return thisCommand;
}


#endif
