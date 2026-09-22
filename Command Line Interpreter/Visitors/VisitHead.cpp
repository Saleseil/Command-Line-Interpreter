#include "VisitHead.h"
#include "../CommandLine/CommandLine.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"

void VisitHead::proccesException() {
	Command* thisCommand = getCommand();
	CommandLine* commandLine = thisCommand->getCommandLine();
	std::vector<std::string>& args = thisCommand->getArguments();
	std::string& argument = args.back();
	size_t size = args.size();
	std::string* opt = thisCommand->getopt();
	if (!opt) {
		throw new SyntaxError("Error: Missing option in command 'head'", thisCommand);
	}
	if (thisCommand->getnumOptArguments() > 1) {
		throw new SyntaxError("Error: To few optional arguments in command 'head'", thisCommand);
	}
	if (opt->length() < 3) {
		throw new SyntaxError("Error: Invalid option type in command 'head'", thisCommand);
	}
	if ((*opt)[1] != 'n') {
		throw new SyntaxError("Error: Invalid option type in command 'head'", thisCommand);
	}
	std::string num = (*opt).substr(2);
	if (num.length() > 5) {
		throw new SyntaxError("Error: Invalid option number in command 'head'", thisCommand);
	}
	for (size_t i = 0; i < num.length(); i++) {
		if (!std::isdigit(num[i])) {
			throw new SyntaxError("Error: Invalid option in command 'head'", thisCommand);
		}
	}
	if (commandLine->checkpipe()) {
		if (size > 2) {
			throw new SyntaxError("Error: To few arguments in command 'head'", thisCommand);
		}
		if (thisCommand->next && commandLine->first != thisCommand) {
			if (args.size() > 1) {
				throw new SyntaxError("Error: Invalid argument in command 'head'", thisCommand);
			}
		}
		if (!thisCommand->next) {
			if (size > 1 && args.back()[0] != '>') {
				throw new SyntaxError("Error: Invalid argument in command 'head'", thisCommand);
			}
		}
	}
	else {
		if (size > 3) {
			throw new SyntaxError("Error: To few arguments in command 'head'", thisCommand);
		}
		if (size == 3 && ((args.back()[0] != '>' && args.back()[0] != '<') || (args.back()[0] == '<' && args[0][1] != '>'))) {
			throw new SyntaxError("Error: Invalid argument in command 'head'", thisCommand);
		}
	}
}