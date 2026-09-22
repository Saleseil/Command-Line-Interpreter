#ifndef VISITREMOVE_H
#define VISITREMOVE_H
#include "VisitCommand.h"

//  Visitor that applies 'rm' command.

class VisitRemove : public VisitCommand {
public:

	VisitRemove(Command* NameCommand);

	virtual void proccesException();

};

inline VisitRemove::VisitRemove(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif 
