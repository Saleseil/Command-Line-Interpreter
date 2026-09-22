#ifndef SYNTAXERROR_H
#define SYNTAXERROR_H
#include "ErrorCommand.h"

//  Errors that are captured from bad syntax for commmand.

class SyntaxError : public ErrorCommand {
public:

	SyntaxError(const std::string& message, Command* command);

	virtual void updateMessage();

	virtual void processError();

};

inline void SyntaxError::updateMessage() {}

#endif
