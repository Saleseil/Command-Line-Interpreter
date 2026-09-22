#ifndef VISITDATE_H
#define VISITDATE_H
#include "VisitCommand.h"

//  Visitor that applies 'date' command.

class VisitDate : public VisitCommand {
public:

	VisitDate(Command* NameCommand);

	virtual void proccesException();

};

inline VisitDate::VisitDate(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif