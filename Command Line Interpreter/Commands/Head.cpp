#include "Head.h"
#include "../Visitors/VisitHead.h"


Head::Head(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Head::checkCommand() {
	VisitCommand = new VisitHead(this);
	VisitCommand->proccesException();
}

void Head::inputFlow() {
	std::vector<std::string>& args = getArguments();
	for (size_t i = 0; i < args.size(); i++) {
		if (args[i][0] == '<') {
			inputFromFile(args[i]);
			return;
		}
	}
	if (args.size() == 1) {
		inputFromConosle();
		return;
	}
	if (args[1][0] == '"') {
		inputFromQuotes(args[1]);
		return;
	}
	inputFromFile(args[1]);
}

void Head::execute() {
	std::string* opt = getopt();
	std::string num = (*opt).substr(2);
	int number = std::stoi(num);
	std::string& input = getinputline();
	std::string& output = getoutputline();
	int i = 0;
	while (input[i] != '\0' && number != 0) {
		if (input[i] == '\n') {
			number--;
		}
		output.push_back(input[i]);
		i++;
	}
	if (output.back() == '\n') output.pop_back();
}