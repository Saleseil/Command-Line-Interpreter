#include "Remove.h"
#include "../Visitors/VisitRemove.h"
#include "../Exceptions/FileError.h"
#include <filesystem>

Remove::Remove(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Remove::checkCommand() {
	VisitCommand = new VisitRemove(this);
	VisitCommand->proccesException();
}

void Remove::inputFlow() {
	setinputline(getArguments()[0]);
}

void Remove::execute() {
	std::string& line = getinputline();
	if (!std::filesystem::remove(line)) {
		throw new FileError("Error: File does not exist", this);
	}
}
