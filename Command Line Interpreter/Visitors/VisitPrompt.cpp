#include "VisitPrompt.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"
#include "../CommandLine/CommandLine.h"

void VisitPrompt::proccesException() {
	std::vector<std::string>& args = getCommand()->getArguments();
	Command* command = getCommand();
	CommandLine* commline = command->getCommandLine();
	if (commline->checkpipe()) {
		throw new SyntaxError("Error: Syntax error with command: 'prompt'", command);
	}
	if (args.size() > 1) {
		throw new SyntaxError("Error: To few arguments in command: 'prompt'", command);
	}
	if (args.empty()) {
		throw new SyntaxError("Error: No argument in command: 'prompt'", command);
	}
	if (args.back()[0] != '"') {
		throw new SyntaxError("Error: Argument must be enclosed in quotation marks", command);
	}
}