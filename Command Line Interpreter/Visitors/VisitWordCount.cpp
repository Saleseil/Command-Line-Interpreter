#include "VisitWordCount.h"
#include "../Exceptions/SyntaxError.h"
#include "../Commands/Command.h"
#include "../CommandLine/CommandLine.h"

void VisitWordCount::proccesException() {
	Command* thisCommand = getCommand();
	CommandLine* commandLine = thisCommand->getCommandLine();
	std::string* opt = thisCommand->getopt();
	std::vector<std::string>& args = thisCommand->getArguments();
	size_t size = args.size();
	if (!opt) {
		throw new SyntaxError("Error: Missing option in command 'wc'", thisCommand);
	}
	if (thisCommand->getnumOptArguments() > 1) {
		throw new SyntaxError("Error: To few optional arguments in command 'wc'", thisCommand);
	}
	if (*opt != "-w" && *opt != "-c") {
		throw new SyntaxError("Error: Invalid option in command 'wc'", thisCommand);
	}
	if (commandLine->checkpipe()) {
		if (size > 2) {
			throw new SyntaxError("Error: To few arguments in command: 'wc'", thisCommand);
		}
		if (!thisCommand->next) {
			if (size > 1 && args.back()[0] != '>') {
				throw new SyntaxError("Error: Invalid argument in command: 'wc'", thisCommand);
			}
		}
		if (thisCommand->next && commandLine->first != thisCommand && size>1) {
			throw new SyntaxError("Error: Invalid argument in command: 'wc'", thisCommand);
		}
	}
	else {
		if (size == 2 && args.back()[0] == '>') {
			throw new SyntaxError("Error: Invalid argument in command: 'wc'", thisCommand);
		}
		if (size > 3) {
			throw new SyntaxError("Error: To few arguments in command: 'wc'", thisCommand);
		}
		if (size == 3 && ((args.back()[0] != '>' && args.back()[0] != '<') || (args.back()[0] == '<' && args[1][0] != '>'))) {
			throw new SyntaxError("Error: Invalid argument in command: 'wc'", thisCommand);
		}
	}
}
