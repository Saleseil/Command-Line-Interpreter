#ifndef INPUTFILESTREAM_H
#define INPUTFILESTREAM_H
#include "FileStream.h"
#include <fstream>

//  Represents an input flow from file.

class InputFileStream : public FileStream {
public:

	//  Constructor that sets the file name from current command.
	InputFileStream(const std::string& fileargument, Command* comm);

	~InputFileStream();

	virtual void print(const std::string& line);

	virtual std::string read();

private:

	//  Pointer to object that created the file stream.
	std::ifstream* file;

	//  Text that has readed from file.
	std::string inputline;

};

inline void InputFileStream::print(const std::string& line) {}

#endif
