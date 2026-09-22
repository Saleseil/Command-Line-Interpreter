#include "VisitTruncate.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"
#include "../CommandLine/CommandLine.h"

void VisitTruncate::proccesException() {
	Command* comm = getCommand();
	CommandLine* commline = comm->getCommandLine();
	std::vector<std::string>& args = comm->getArguments();
	if (commline->checkpipe()) {
		throw new SyntaxError("Error: Syntax error with command: 'truncate'", comm);
	}
	if (args.size() > 1) {
		throw new SyntaxError("Error: To few arguments in command: 'truncate'", comm);
	}
	if (args.empty()) {
		throw new SyntaxError("Error: Missing argument in command: 'truncate'", comm);
	}
	if (comm->getopt()) {
		throw new SyntaxError("Error: No options in commmand: 'touch'", comm);
	}
}
