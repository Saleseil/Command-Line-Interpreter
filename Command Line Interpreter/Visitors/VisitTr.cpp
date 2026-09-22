#include "VisitTr.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"
#include "../CommandLine/CommandLine.h"

void VisitTr::proccesException() {
	Command* thisCommand = getCommand();
	CommandLine* commandLine = thisCommand->getCommandLine();
	std::vector<std::string>& args = thisCommand->getArguments();
	size_t size = args.size();
	std::string& input = thisCommand->getinputline();
	if (args.empty()) {
		throw new SyntaxError("Error: Missing arguments in command 'tr'", thisCommand);
	}
	if (commandLine->checkpipe()) {
		if (thisCommand->next && commandLine->first == thisCommand) {
			if (size > 3) {
				throw new SyntaxError("Error: To few arguments in command: 'tr'", thisCommand);
			}
			if (size == 2 && args[0][0] == '"' && args[1][0] != '<') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
			if (size == 3) {
				int q = 0;
				for (size_t i = 0; i < size; i++) {
					if (args[i][0] == '"') q++;
				}
				if (q < 2) {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
			}
		}
		if (thisCommand->next && commandLine->first != thisCommand) {
			if (size > 2) {
				throw new SyntaxError("Error: To few arguments in command: 'tr'", thisCommand);
			}
			if (size == 2 && (args[1][0] != '"' || args[0][0] != '"')) {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
			if (args.back()[0] != '"') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
		}
		if (!thisCommand->next) {
			if (size > 3) {
				throw new SyntaxError("Error: To few arguments in command: 'tr'", thisCommand);
			}
			if (size == 1 && args[0][0] != '"') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
			if (size == 2 && args.back()[0] != '>' && args.back()[0] != '"') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
			if (size == 3 && args[1][0] != '"') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
			if (size == 3 && args.back()[0] != '>') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
		}
	}
	else {
		int q = 0;
		for (size_t i = 0; i < size; i++) {
			if (args[i][0] == '"') q++;
		}
		if (size > 4) {
			throw new SyntaxError("Error: To few arguments in command: 'tr'", thisCommand);
		}
		if (size==0) {
			throw new SyntaxError("Error: Missing arguments in command 'tr'", thisCommand);
		}
		if (size == 1 && args.back()[0] != '"') {
			throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
		}
		if (size == 2) {
			if (args[0][0] != '"' && args[1][0] != '"') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
			if (q == 1 && args[0][0] == '"' && args[1][0] != '<') {
				throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
			}
		}
		if (size == 3) {
			if (!q) {
				throw new SyntaxError("Error: Invalid arguments in command 'tr'", thisCommand);
			}
			if (q == 1) {
				if (args.back()[0] != '>' && args.back()[0] != '<') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[0][0] == '"' && args[1][0] != '>' && args[1][0] != '<') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[1][0] == '"' && args.back()[0] != '>') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
			}
			if (q == 2) {
				if (args[0][0] == '"' && args[1][0] == '"' && (args[2][0] != '<' && args[2][0] != '>')) {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[0][0] == '"' && args[1][0] != '"' && args.back()[0] == '"') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
			}
		}
		if (size == 4) {
			if (q < 2) {
				throw new SyntaxError("Error: Invalid arguments in command 'tr'", thisCommand);
			}
			if (q > 3) {
				throw new SyntaxError("Error: Invalid arguments in command 'tr'", thisCommand);
			}
			if (q == 2) {
				if (args[0][0] == '"' && args[1][0] == '"' && ((args[2][0] != '<' && args[2][0] != '>') || (args[3][0] != '<' && args[3][0] != '>'))) {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[0][0] == '"' && args[2][0] == '"') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[0][0] == '"' && args[3][0] == '"') {
					throw new SyntaxError("Eroor: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[1][0] == '"' && args[2][0] == '"' && args[3][0] != '>') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[2][0] == '"' && args[3][0] == '"') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
				if (args[1][0] == '"' && args[3][0] == '"') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
			}
			if (q == 3) {
				if (args.back()[0] != '>') {
					throw new SyntaxError("Error: Invalid argument in command 'tr'", thisCommand);
				}
			}
		}
	}
}