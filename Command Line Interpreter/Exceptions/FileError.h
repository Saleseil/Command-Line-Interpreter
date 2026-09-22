#ifndef FILEERROR_H
#define FILEERROR_H
#include "ErrorCommand.h"

//  Errors during opening, reading and writing in file.

class FileError : public ErrorCommand {
public:
	
	FileError(const std::string& message, Command* command);

	virtual void processError();

	virtual void updateMessage();

};

inline void FileError::updateMessage() {}


#endif