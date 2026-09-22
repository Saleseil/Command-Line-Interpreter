#include "VisitBatch.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"
#include "../CommandLine/CommandLine.h"

void VisitBatch::proccesException() {
	Command* thisCommand = getCommand();
	CommandLine* commandLine = thisCommand->getCommandLine();
	std::vector<std::string>& args = thisCommand->getArguments();
	if (commandLine->checkpipe()) {
		if (commandLine->first == thisCommand || (commandLine->first != thisCommand && thisCommand->next)) {
			throw new SyntaxError("Error: Command 'batch' cannot be in pipe even on the end", thisCommand);
		}
		if (args.size() > 1) {
			throw new SyntaxError("Error: To few arguments in command 'batch'", thisCommand);
		}
		if (args.size() > 0 && args[0][0] != '>') {
			throw new SyntaxError("Error: Invalid argument in command 'batch'", thisCommand);
		}
	}
	if (args.size() > 2) {
		throw new SyntaxError("Error: To few arguments in command 'batch'", thisCommand);
	}
}