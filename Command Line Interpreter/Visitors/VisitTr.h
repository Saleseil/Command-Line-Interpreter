#ifndef VISITTR_H
#define VISITTR_H
#include "VisitCommand.h"

//  Visitor that applies 'tr' command.

class VisitTr : public VisitCommand {
public:

	VisitTr(Command* NameCommand);

	virtual void proccesException();

};

inline VisitTr::VisitTr(Command* NameCommand) : VisitCommand(NameCommand) {};


#endif 
