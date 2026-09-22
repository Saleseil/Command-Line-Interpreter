#ifndef VISITPROMPT_H
#define VISITPROMPT_H
#include "VisitCommand.h"

//  Visitor that applies 'prompt' command.

class VisitPrompt : public VisitCommand {
public:

	VisitPrompt(Command* NameCommand);

	virtual void proccesException();

};

inline VisitPrompt::VisitPrompt(Command* NameCommand) : VisitCommand(NameCommand) {};

#endif 