#include "Touch.h"
#include "../Visitors/VisitTouch.h"
#include "../Exceptions/FileError.h"
#include <fstream>
#include <filesystem>

Touch::Touch(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Touch::checkCommand() {
	VisitCommand = new VisitTouch(this);
	VisitCommand->proccesException();
}

void Touch::inputFlow() {
	setinputline(getArguments()[0]);
}

void Touch::execute() {
	std::string& filename = getinputline();
	if (filename == "") return;
	if (std::filesystem::exists(filename)) {
		throw new FileError("Error: File already exist", this);
	}
	std::ofstream make(filename);
	if (!make.is_open()) {
		make.close();
		throw new FileError("Error: Error with creating file: " + filename, this);
	};
	make.close();
}