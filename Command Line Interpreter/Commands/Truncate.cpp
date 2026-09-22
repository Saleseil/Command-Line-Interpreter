#include "Truncate.h"
#include "../Exceptions/FileError.h"
#include "../Visitors/VisitTruncate.h"
#include <fstream>
#include <filesystem>

Truncate::Truncate(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Truncate::checkCommand() {
	VisitCommand = new VisitTruncate(this);
	VisitCommand->proccesException();
}

void Truncate::inputFlow() {
	setinputline(getArguments()[0]);
}

void Truncate::execute() {
	std::string& filename = getinputline();
	if (!std::filesystem::exists(filename)) {
		throw new FileError("Error: File does not exist", this);
	}
	std::ofstream clear(filename);
	if (!clear.is_open()) {
		clear.close();
		throw new FileError("Error: Error with creating file: " + filename, this);
	}
	clear.close();
}