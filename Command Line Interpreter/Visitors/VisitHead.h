#ifndef VISITHEAD_H
#define VISITHEAD_H
#include "VisitCommand.h"

//  Visitor that applies 'head' command.

class VisitHead : public VisitCommand {
public:

	VisitHead(Command* NameCommand);

	virtual void proccesException();

};

inline VisitHead::VisitHead(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif 
