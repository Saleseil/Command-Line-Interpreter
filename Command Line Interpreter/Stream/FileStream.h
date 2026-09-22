#ifndef FILESTREAM_H
#define FILESTREAM_H
#include "Stream.h"

//  Represents an abstraction of streams for files.

class Command;

class FileStream : public Stream {

protected:

	//  Returns a name of the file.  
	virtual std::string& getFilename();

	//  Sets a name of the file.
	virtual void setFilename(const std::string& name);

	FileStream(Command* command);

	//  Pointer to current command.
	Command* command;

private:

	//  Name of the file.
	std::string filename;

};

inline FileStream::FileStream(Command* command) : command(command) {}

inline std::string& FileStream::getFilename() {
	return filename;
}

inline void FileStream::setFilename(const std::string& name) {
	filename = name;
}

#endif