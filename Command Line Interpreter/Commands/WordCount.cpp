#include "WordCount.h"
#include "../Visitors/VisitWordCount.h"

WordCount::WordCount(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void WordCount::checkCommand() {
	VisitCommand = new VisitWordCount(this);
	VisitCommand->proccesException();
}

void WordCount::inputFlow() {
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
	if (args[1][0] == '"') {
		inputFromQuotes(args[1]);
		return;
	}
	inputFromFile(args[1]);
}

void WordCount::execute() {
	std::string* opt = getopt();
	if ((*opt) == "-w") {
		wordcount();
	}
	if ((*opt) == "-c") {
		charcount();
	}
}

void WordCount::charcount() {
	std::string& line = getinputline();
	std::string currline;
	size_t i = 0;
	size_t len = line.length();
	if (line[len - 1] == EOF) len--;
	while (i < len) {
		currline.push_back(line[i]);
		i++;
		/*
		i++;
		while (i < len && line[i] == '\n') {
			currline.push_back(line[i]);
			i++;
		}
		*/
	}
	size_t newsize = currline.length();
	std::string count = std::to_string(newsize);
	setoutputline(count);
}

void WordCount::wordcount() {
	std::string& input = getinputline();
	int spaces = 0;
	int i = 0;
	size_t len = getinputline().length();
	while (i < len) {
		if (std::isspace(input[i])) {
			spaces++;
			while (std::isspace(input[i])) i++;
			continue;
		}
		i++;
	}
	spaces += 1;
	std::string& wordscount = getoutputline();
	wordscount = std::to_string(spaces);
}