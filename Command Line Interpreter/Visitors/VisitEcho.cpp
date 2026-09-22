#include "VisitEcho.h"
#include "../Exceptions/SyntaxError.h"
#include "../CommandLine/CommandLine.h"
#include "../Commands/Command.h"

void VisitEcho::proccesException() {
	Command* thisCommand = getCommand();
	CommandLine* commandLine = thisCommand->getCommandLine();
	std::vector<std::string>& args = thisCommand->getArguments();
	size_t size = args.size();
	if (thisCommand->getopt()) {
		throw new SyntaxError("Error: Invalid argument in command 'echo'", thisCommand);
	}
	if (commandLine->checkpipe()) {
		if (size > 1) {
			throw new SyntaxError("Error: To few arguments in command: 'echo'", thisCommand);
		}
		if (!thisCommand->next) {
			if (size > 0 && args.back()[0] != '>') {
				throw new SyntaxError("Error: Invalid argument in command: 'echo'", thisCommand);
			}
		}
		if (thisCommand->next && commandLine->first != thisCommand && size > 0) {
			throw new SyntaxError("Error: Invalid argument in command: 'echo'", thisCommand);
		}
	}
	else {
		if (size == 1 && args.back()[0] == '>') {
			throw new SyntaxError("Error: Invalid argument in command 'echo'", thisCommand);
		}
		if (size > 2) {
			throw new SyntaxError("Error: To few arguments in command: 'echo'", thisCommand);
		}
		if (size == 2 && ((args[1][0] != '>' && args[1][0] != '<') || (args[1][0] == '<' && args[0][0] != '>'))) {
			throw new SyntaxError("Error: Invalid argument in command: 'echo'", thisCommand);
		}
	}
};