#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>

//  Interface which does exception handling and printing the error message in commands and command line.

class ErrorMessage : public std::exception {
public:

	//  Print the error message in all commands or in the command line.
	virtual void processError() = 0;

	//  Update error message with useful information.
	virtual void updateMessage() = 0;

	//  Method which can print a more informations about the error.
	virtual void informationUnit();

	//  Sets error message.
	virtual void setMessage(const std::string& message);

	//  Returns the error message.	
	virtual std::string& getMessage();

private:

	//  Error message.
	std::string msg;

};

inline void ErrorMessage::informationUnit() {}

inline void ErrorMessage::setMessage(const std::string& message) {
	msg = message;
}

inline std::string& ErrorMessage::getMessage() {
	return msg;
}

#endif 
