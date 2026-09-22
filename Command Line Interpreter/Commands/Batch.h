#ifndef BATCH_H
#define BATCH_H
#include "Command.h"

//  A command that execute all commands from console or from input file.

class Batch : public Command {
public:

	//  Constructor.
	Batch(const std::string& name, CommandLine* commLine);

	//  Destroy command lines.
	~Batch();

	virtual void checkCommand();

	virtual void execute();

protected:
	
	//  Add a text line in the result line of command.
	virtual void addforoutput(std::string& line);

	//  Redirect output flow of all command lines.
	virtual void redirectflow();

	//  Redirect the errors of all command lines.
	virtual void redirectError();

	//  Add command line to the end of the list.
	virtual void put(CommandLine* commLine);

private:
	
	//  Pointer to the first command line.
	CommandLine* firstComLine;

	//  Pointer to the last command line.
	CommandLine* lastComLine;

	//  Line that will be evry command line.
	std::string line;

};


#endif