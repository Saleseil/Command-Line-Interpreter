#ifndef VISITWORDCOUNT_H
#define VISITWORDCOUNT_H
#include "VisitCommand.h"

//  Visitor that applies 'wc' command.

class VisitWordCount : public VisitCommand {
public:

	VisitWordCount(Command* NameCommand);

	virtual void proccesException();

};

inline VisitWordCount::VisitWordCount(Command* NameCommand) : VisitCommand(NameCommand) {};


#endif
