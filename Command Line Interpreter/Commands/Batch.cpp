#include "Batch.h"
#include "../Visitors/VisitBatch.h"
#include "../Exceptions/Exceptions.h"
#include "../CommandLine/CommandLine.h"

Batch::Batch(const std::string& name, CommandLine* commLine) : Command(name, commLine), firstComLine(nullptr), lastComLine(nullptr){}

Batch::~Batch() {
	delete firstComLine;
}

void Batch::checkCommand() {
	VisitCommand = new VisitBatch(this);
	VisitCommand->proccesException();
}

void Batch::put(CommandLine* commLine) {
	if (!firstComLine) {
		firstComLine = commLine;
		lastComLine = commLine;
		return;
	}
	lastComLine->setNextCommLine(commLine);
	lastComLine = commLine;
}

void Batch::redirectflow() {
	if (lastComLine->last->checkoutredirection()) {
		lastComLine->outputCommandLineFlow();
		return;
	}
	addforoutput(lastComLine->last->getoutputline());
}

void Batch::redirectError() {
	if (!lastComLine->getErrorLine().empty()) addforoutput(lastComLine->getErrorLine());
	else if (lastComLine->current) {
		addforoutput(lastComLine->current->getErrorLine());
	}
}

void Batch::addforoutput(std::string& line) {
	std::string& out = getoutputline();
	if (out.empty()) {
		out += line;
		return;
	}
	out = out + '\n' + line;
}

void Batch::execute() {
	std::string& input = getinputline();
	int i = 0;
	while (input[i] != '\0') {
		line = "";
		while (input[i] != '\n' && input[i] != '\0') {
			line.push_back(input[i]);
			i++;
		}
		if (input[i] == '\n') {
			i++;
			while (input[i] == ' ' || input[i] == '\t') i++;
		}
		try {
			put(CommandLine::create());
			lastComLine->setreadline(line);
			lastComLine->readLine();
			lastComLine->inputCommandLineFlow();
			lastComLine->executeLine();
			redirectflow();
		}
		catch (LexicalError* e) {
			e->processError();
			redirectError();
			delete e;
		}
		catch (UnknownCommandError* e) {
			e->processError();
			redirectError();
			delete e;
		}
		catch (SyntaxError* e) {
			e->processError();
			redirectError();
			delete e;
		}
		catch (FileError* e) {
			e->processError();
			redirectError();
			delete e;
		}
	}
}