#include "Tr.h"
#include "../CommandLine/CommandLine.h"
#include "../Visitors/VisitTr.h"

Tr::Tr(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Tr::checkCommand() {
	VisitCommand = new VisitTr(this);
	VisitCommand->proccesException();
}

void Tr::inputFlow() {
	std::vector<std::string>& args = getArguments();
	if (args.size() == 1) {
		inputFromConosle();
		return;
	}
	for (size_t i = 0; i < args.size(); i++) {
		if (args[i][0] == '<') {
			inputFromFile(args[i]);
			return;
		}
	}
	if (args[0][0] == '"') {
		inputFromQuotes(args[0]);
		return;
	}
	inputFromFile(args[0]);
}

void Tr::setInPipe(std::string& what, std::string& with) {
	std::vector<std::string>& args = getArguments();
	if ((!next) || (next && getCommandLine()->first != this)) {
		what = args[0];
		if (args.size() > 1) {
			if (args[1][0] == '"') {
				with = args[1];
			}
		}
	}
}

void Tr::setWithoutPipe(std::string& what, std::string& with) {
	std::vector<std::string>& args = getArguments();
	size_t size = args.size();
	int m = 0;
	int checkin = 0;
	int checkout = 0;
	for (size_t i = 0; i < size; i++) {
		if (args[i][0] == '"') m++;
		if (args[i][0] == '<') checkin++;
		if (args[i][0] == '>') checkout++;
	}
	if (m == 1) {
		for (size_t i = 0; i < size; i++) {
			if (args[i][0] == '"') {
				what = args[i];
				break;
			}
		}
	}
	if (m == 2) {
		if (size == 2) {
			what = args.back();
		}
		if (size == 3) {
			if (args[0][0] != '"' && !checkin) {
				what = args[1];
				with = args[2];
			}
			if (checkin) {
				what = args[0];
				with = args[1];
			}
			if (checkout) {
				what = args[1];
			}
		}
		if (size == 4) {
			if (checkin) {
				what = args[0];
				with = args[1];
			}
			if (!checkin && args[0][0] != '"') {
				what = args[1];
				with = args[2];
			}
		}
	}
	if (m == 3) {
		if (size == 3 || size == 4) {
			what = args[1];
			with = args[2];
		}
	}
}

void Tr::setWhatandWith(std::string& what, std::string& with) {
	if (getCommandLine()->checkpipe()) setInPipe(what, with);
	else setWithoutPipe(what, with);
}

void Tr::execute() {
	std::vector<std::string>& args = getArguments();
	std::string& input = getinputline();
	size_t size = args.size();
	CommandLine* commandLine = this->getCommandLine();
	int m = 0;
	int checkin = 0;
	int checkout = 0;
	std::string what = "";
	std::string with = "";
	setWhatandWith(what, with);

	what = what.substr(1, what.length() - 2);
	if (with != "") {
		with = with.substr(1, with.length() - 2);
	}

	size_t start_pos = 0;
	
	while ((start_pos = input.find(what, start_pos)) != std::string::npos) {
		input.replace(start_pos, what.length(), with);
		start_pos += with.length(); 
	}
	setoutputline(input);
}