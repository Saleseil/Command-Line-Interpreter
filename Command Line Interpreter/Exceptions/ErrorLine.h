#ifndef ERRORLINE_H
#define ERRORLINE_H
#include <string>

//  Interface of all commands and command line which print errors.

class ErrorLine {
public:

	//  Print the message of error in the output.
	virtual void printError() = 0;

	//  Sets the error message.
	virtual void setErrorLine(const std::string& line);

	//  Returns the error message.
	virtual std::string& getErrorLine();

private:

	//  Error message wich will be print in the output.
	std::string errorLine;

};

inline void ErrorLine::setErrorLine(const std::string& line) {
	errorLine = line;
}

inline std::string& ErrorLine::getErrorLine() {
	return errorLine;
}


#endif 

