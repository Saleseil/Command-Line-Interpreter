#include "VisitTime.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"

void VisitTime::proccesException() {
	std::vector<std::string>& args = getCommand()->getArguments();
	Command* command = getCommand();
	if (args.size() > 1) {
		throw new SyntaxError("Error: To few arguments in command: 'time'", command);
	}
	if (!args.empty() && args.back()[0] != '>') {
		throw new SyntaxError("Error: Invalid argument in command: 'time'", command);
	}
	if (!command->getinputline().empty()) {
		throw new SyntaxError("Error: Syntax error in command: 'time'", command);
	}
}