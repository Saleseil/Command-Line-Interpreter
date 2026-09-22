#include "ConsoleStream.h"
#include "../CommandLine/CommandLine.h"
#include "../Exceptions/Exceptions.h"
#include "../Commands/Command.h"
#include <iostream>


ConsoleStream::~ConsoleStream() {
	delete commandline;
}

void ConsoleStream::run() {
	while (true) {
		try {
			std::cout << promptr << " ";
			std::getline(std::cin, line);
			if (line == "exit") break;
			if (line == "") continue;
			commandline = CommandLine::create();
			commandline->setreadline(line);
			commandline->readLine();
			commandline->inputCommandLineFlow();
			commandline->executeLine();
			commandline->outputCommandLineFlow();
		}
		catch (LexicalError* e) {
			e->processError();
			commandline->printError();
			delete e;
		}
		catch (UnknownCommandError* e) {
			e->processError();
			commandline->printError();
			delete e;
		}
		catch (SyntaxError* e) {
			e->processError();
			commandline->current->printError();
			delete e;
		}
		catch (FileError* e) {
			e->processError();
			commandline->current->printError();
			delete e;
		}
		delete commandline;
	}
	commandline = nullptr;
}

std::string ConsoleStream::read() {
	int c;
	std::string part;
	while ((c = std::cin.get()) != EOF) {
		part += static_cast<char>(c);
	}
	size_t iter = part.length() - 1;
	while (iter > 0 && part[iter] == '\n') {
		part.pop_back();
		iter--;
	}
	std::cin.clear();
	return part;
}

void ConsoleStream::print(const std::string& line) {
	std::cout << line << std::endl;
}

ConsoleStream* ConsoleStream::Insstance() {
	static ConsoleStream ConsoleStream;
	return &ConsoleStream;
}