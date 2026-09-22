#ifndef VISITTRUNCATE_H
#define VISITTRUNCATE_H
#include "VisitCommand.h"

//  Visitor that applies 'truncate' command.

class VisitTruncate : public VisitCommand {
public:

	VisitTruncate(Command* NameCommand);

	virtual void proccesException();

};

inline VisitTruncate::VisitTruncate(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif
