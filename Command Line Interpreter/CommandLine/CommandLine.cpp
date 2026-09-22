#include "CommandLine.h"
#include "../Commands/Commands.h"
#include "../Visitors/VisitCommandLine.h"
#include "../Stream/ConsoleStream.h"
#include "../Lexer/Lexer.h"
CommandLine::CommandLine() : first(nullptr), current(nullptr), last(nullptr), nextCommLine(nullptr) {
	lexer = new Lexer(this);
	visCommandLine = new VisitCommandLine(this, lexer->getTokens());
}

CommandLine::~CommandLine(){
	clear();
	delete visCommandLine;
	delete nextCommLine;
	delete lexer;
}

CommandLine* CommandLine::create() {
	return new CommandLine();
}

void CommandLine::inputCommandLineFlow() {
	if (first) {
		current = first;
		first->checkCommand();
		first->inputFlow();
	} 
}

void CommandLine::outputCommandLineFlow() {
	if (last) last->outputFlow();
}

void CommandLine::printError() {
	ConsoleStream::Insstance()->print(getErrorLine());
}

void CommandLine::setreadline(const std::string& line) {
	readline = "";
	int i = 0;
	while (i < 512 && line[i] != '\0') {
		readline.push_back(line[i]);
		i++;
	}
}

void CommandLine::clear() {
	Command* curr = nullptr;
	while (first) {
		curr = first;
		first = first->next;
		delete curr;
	}
}

bool CommandLine::checkpipe() {
	const std::vector<Token>* tokens = lexer->getTokens();
	for (size_t i = 0; i < tokens->size(); i++) {
		if ((*tokens)[i].type == Pipe) return true;
	}
	return false;
}

void CommandLine::choose() {
	if (commandName == "echo") echo();
	if (commandName == "prompt") prompt();
	if (commandName == "touch") touch();
	if (commandName == "time") time();
	if (commandName == "date") date();
	if (commandName == "truncate") truncate();
	if (commandName == "rm") remove();
	if (commandName == "wc") wordCount();
	if (commandName == "tr") trWhat();
	if (commandName == "head") head();
	if (commandName == "batch") batch();
}

void CommandLine::assign(const std::string& command) {
	setName(command);
	visCommandLine->checkCommandName(commandName);
	choose();
}

void CommandLine::parseCommandLine() {
	const std::vector<Token>* tokens = lexer->getTokens();
	if (!tokens) return;
	size_t i = 0;
	while (i < tokens->size()) {
		if (i == 0) {
			assign((*tokens)[i].value);
			i++;
			continue;
		}
		if ((*tokens)[i].type == Pipe) {
			assign((*tokens)[i+1].value);
			i+=2;
			continue;
		}
		if ((*tokens)[i].type == InputRedirect || (*tokens)[i].type == OutputRedirect || (*tokens)[i].type == AppendRedirect) {
			size_t e = i;
			i++;
			last->addArgument((*tokens)[e].value + (*tokens)[i].value);
			i++; continue;
		}
		if (last) last->addArgument((*tokens)[i].value);
		i++;
	}
}

void CommandLine::readLine() {
	lexer->createTokens(readline);
	visCommandLine->proccesException();
	parseCommandLine();
}

void CommandLine::add(Command* tail) {
	if (!first) {
		first = tail;
		last = tail;
		return;
	}
	last->next = tail;
	last = tail;
}

void CommandLine::executeLine() {
	if (!first) return;
	current = first;
	current->execute();
	if (!checkpipe()) return;
	if (current->next){
		current->next->setinputline(current->getoutputline());
		current = current->next;
	}
	while (current->next) {
		current->checkCommand();
		current->execute();
		current->next->setinputline(current->getoutputline());
		current = current->next;
	}
	current->checkCommand();
	current->execute();
}

void CommandLine::echo() {
	Command* tail = new Echo(commandName, this);
	add(tail);
}
void CommandLine::prompt() {
	Command* tail = new Prompt(commandName, this);
	add(tail);
}
void CommandLine::touch() {
	Command* tail = new Touch(commandName, this);
	add(tail);
}
void CommandLine::time() {
	Command* tail = new Time(commandName, this);
	add(tail);
}
void CommandLine::date() {
	Command* tail = new Date(commandName, this);
	add(tail);
}
void CommandLine::truncate() {
	Command* tail = new Truncate(commandName, this);
	add(tail);
}
void CommandLine::remove() {
	Command* tail = new Remove(commandName, this);
	add(tail);
}
void CommandLine::wordCount() {
	Command* tail = new WordCount(commandName, this);
	add(tail);
}
void CommandLine::trWhat() {
	Command* tail = new Tr(commandName, this);
	add(tail);
}
void CommandLine::head() {
	Command* tail = new Head(commandName, this);
	add(tail);
}
void CommandLine::batch() {
	Command* tail = new Batch(commandName, this);
	add(tail);
}