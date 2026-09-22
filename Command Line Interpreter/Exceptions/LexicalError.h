#ifndef LEXICALERROR_H
#define LEXICALERROR_H
#include "ErrorCommandLine.h"


class LexicalError : public ErrorCommandLine {
public:

	LexicalError(CommandLine* commandLine, const std::string& errorMess);

	virtual void processError();

	virtual void updateMessage();

};

#endif