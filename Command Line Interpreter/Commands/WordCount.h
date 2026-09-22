#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include "Command.h"

//  A command that count the number of words or the number of characters form a console or from a file.

class WordCount : public Command {
public:

	//  Constructor.
	WordCount(const std::string& name, CommandLine* commLine);

	virtual void checkCommand();

	//  Redefined.
	virtual void inputFlow();

	virtual void execute();

protected:

	//  Count the number of words.
	virtual void wordcount();

	//  Count the number of characters.
	virtual void charcount();

};



#endif
