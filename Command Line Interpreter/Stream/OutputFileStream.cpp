#include "OutputFileStream.h"
#include "../Exceptions/FileError.h"


OutputFileStream::OutputFileStream(const std::string& fileargument, std::string simbol, Command* comm) : FileStream(comm), file(nullptr) {
	this->simbol = simbol;
	int i = 0;
	while (fileargument[i] == '>' || fileargument[i] == ' ' || fileargument[i] == '\t') i++;
	std::string line = fileargument.substr(i);
	setFilename(line);
}

OutputFileStream::~OutputFileStream() {
	delete file;
}

void OutputFileStream::print(const std::string& line) {
	if (simbol == ">") {
		file = new std::ofstream(getFilename(), std::ios::out);
	}
	if (simbol == ">>") {
		file = new std::ofstream(getFilename(), std::ios::app);
	}
	if (!file->is_open()) {
		file->close();
		throw new FileError("Error: Error with writing in file", command);
	}
	*file << line;
	file->close();	
}

