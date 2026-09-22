#include "Echo.h"
#include "../Visitors/VisitEcho.h"

Echo::Echo(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Echo::checkCommand() {
	VisitCommand = new VisitEcho(this);
	VisitCommand->proccesException();
}

void Echo::execute() {
	setoutputline(getinputline());
}


