#ifndef VISITECHO_H
#define VISITECHO_H
#include "VisitCommand.h"

//  Visitor that applies 'echo' command.


class VisitEcho : public VisitCommand {
public:

	VisitEcho(Command* NameCommand);

	virtual void proccesException();

};

inline VisitEcho::VisitEcho(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif 
