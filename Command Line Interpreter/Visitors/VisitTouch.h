#ifndef VISITTOUCH_H
#define VISITTOUCH_H
#include "VisitCommand.h"

//  Visitor that applies 'touch' command.

class VisitTouch : public VisitCommand {
public:

	VisitTouch(Command* NameCommand);

	virtual void proccesException();

};

inline VisitTouch::VisitTouch(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif
