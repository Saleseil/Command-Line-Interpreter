#include "VisitDate.h"
#include "../Commands/Command.h"
#include "../Exceptions/SyntaxError.h"

void VisitDate::proccesException() {
	std::vector<std::string>& args = this->getCommand()->getArguments();
	Command* command = this->getCommand();
	if (args.size() > 1) {
		throw new SyntaxError("Syntax error: To few arguments in command: 'date'", command);
	}
	if (!args.empty() && args.back()[0] != '>') {
		throw new SyntaxError("Syntax error: Invalid argument in command: 'date'", command);
	}
	if (!command->getinputline().empty()) {
		throw new SyntaxError("Syntax error: Syntax error in command: 'date'", command);
	}
}