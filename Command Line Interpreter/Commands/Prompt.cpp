#include "Prompt.h"
#include "../Stream/ConsoleStream.h"
#include "../Visitors/VisitPrompt.h"

Prompt::Prompt(const std::string& name, CommandLine* commLine) : Command(name, commLine){}

void Prompt::checkCommand() {
	VisitCommand = new VisitPrompt(this);
	VisitCommand->proccesException();
}

void Prompt::inputFlow() {
	std::vector<std::string>& args = getArguments();
	inputFromQuotes(args[0]);
}

void Prompt::execute() {
	clsStream = ConsoleStream::Insstance();
	clsStream->setPrompt(getinputline());
}


