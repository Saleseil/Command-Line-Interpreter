#ifndef VISITBATCH_H
#define VISITBATCH_H
#include "VisitCommand.h"

//  Visitor that applies 'batch' command.

class VisitBatch : public VisitCommand {
public:

	VisitBatch(Command* NameCommand);

	virtual void proccesException();

};

inline VisitBatch::VisitBatch(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif
