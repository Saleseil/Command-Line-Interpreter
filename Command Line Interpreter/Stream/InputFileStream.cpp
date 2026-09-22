#include "InputFileStream.h"
#include "../Exceptions/FileError.h"
#include <filesystem>



InputFileStream::InputFileStream(const std::string& fileargument, Command* comm) : FileStream(comm), file(nullptr) {
	int i = 0;
	while (fileargument[i] == '<' || fileargument[i] == ' ' || fileargument[i] == '\t') i++;
	std::string line = fileargument.substr(i);
	setFilename(line);
}

InputFileStream::~InputFileStream() {
	delete file;
}

std::string InputFileStream::read() {
	if (!std::filesystem::exists(getFilename())) {
		throw new FileError("Error: File does not exist", command);
	}
	file = new std::ifstream(getFilename());
	if (!file->is_open()) {
		file->close();
		throw new FileError("Error: Error with reading file", command);
	}
	std::string line;
	while (std::getline(*file, line)) {
		inputline += line;
		inputline += '\n';
	}
	if (inputline == "") {
		return "";
	};
	inputline.pop_back();
	inputline.push_back('\0');
	file->close();
	return inputline;
}

