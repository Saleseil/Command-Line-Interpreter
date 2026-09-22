#include "VisitRemove.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"
#include "../CommandLine/CommandLine.h"

void VisitRemove::proccesException(){
	Command* comm = getCommand();
	CommandLine* commline = comm->getCommandLine();
	std::vector<std::string>& args = comm->getArguments();
	if (commline->checkpipe()) {
		throw new SyntaxError("Error: Syntax error with command: 'remove'", comm);
	}
	if (args.size() > 1) {
		throw new SyntaxError("Error: To few arguments in command: 'remove'", comm);
	}
	if (args.empty()) {
		throw new SyntaxError("Error: Missing argument in command: 'remove'", comm);
	}
	if (comm->getopt()) {
		throw new SyntaxError("Error: No options in commmand: 'remove'", comm);
	}
}
