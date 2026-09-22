#ifndef VISITTIME_H
#define VISITTIME_H
#include "VisitCommand.h"

//  Visitor that applies 'time' command.

class VisitTime : public VisitCommand {
public:

	VisitTime(Command* NameCommand);

	virtual void proccesException();

};

inline VisitTime::VisitTime(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif 
