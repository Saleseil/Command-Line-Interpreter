#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include "../Exceptions/ErrorLine.h"

//  Represents a object that has a task to execute one or more commands.

class Command;
class VisitCommandLine;
class Lexer;

class CommandLine : public ErrorLine{
public:

	~CommandLine();

	//  Static method that create the command line object.
	static CommandLine* create();

	//  Sets the command line string. 
	virtual void setreadline(const std::string& line);

	//  Returns the command line string.
	virtual std::string& getreadline();

	//  Checks if there is a pipe mechanism in the command line.
	virtual bool checkpipe();

	//  Read the input flow from the first command.
	virtual void inputCommandLineFlow();

	//  Create the commands in a row in command line.
	virtual void readLine();

	//  Execute all commands in command line.
	virtual void executeLine();

	//  Print the result of last command in his output.
	virtual void outputCommandLineFlow();

	//  Print the error message in the console.
	virtual void printError();

	//  Sets the next command line pointer.
	virtual void setNextCommLine(CommandLine* commLine);

	//  Returns the next command line pointer.
	virtual CommandLine* getNextCommLine();

	//  Visitor that checks and prints if there is a some lexical problems in command line.
	VisitCommandLine* visCommandLine;

	//  Pointer to the first created command in command line.
	Command* first;

	//  Pointer to the current command being executed in command line.
	Command* current;

	//  Pointer to the last created command in command line.
	Command* last;

protected:

	//  Constructor. Create the command line.
	CommandLine();

	//  Sets name of current command.
	virtual void setName(const std::string& line);

	//  Choose whichh command will be created.
	virtual void choose();

	//  Add the command in the list of created commands.
	virtual void add(Command* tail);

	//  Set and create the current command.
	virtual void assign(const std::string& line);

	//  Split the commands that can be created in command line.
	virtual void parseCommandLine();

	//  Destroy commands in command line.
	virtual void clear();

	//  Crreate 'echo' command.
	virtual void echo();

	//  Create a 'prompt' command.
	virtual void prompt();

	//  Create a 'touch' command.
	virtual void touch();

	//  Create a 'time' command.
	virtual void time();
	
	//  Create a 'date' command.
	virtual void date();

	//  Create a 'truncate' command.
	virtual void truncate();

	//  Create a 'rm' command.
	virtual void remove();

	//  Create a 'wc' command.
	virtual void wordCount();

	//  Create a 'tr' command.
	virtual void trWhat();

	//  Create a 'head' command.
	virtual void head();

	//  Create a 'batch' command.
	virtual void batch();

private:

	//  Name of current command to be executed.
	std::string commandName;

	//  Part of command line without command name.
	std::string part;

	//  Whole command line to be executed.
	std::string readline;

	//  Pointer to next command line.
	CommandLine* nextCommLine;

	//  Lexer for current command line.
	Lexer* lexer;

};

inline std::string& CommandLine::getreadline() {
	return readline;
}

inline CommandLine* CommandLine::getNextCommLine() {
	return nextCommLine;
}

inline void CommandLine::setNextCommLine(CommandLine* commLine) {
	nextCommLine = commLine;
}

inline void CommandLine::setName(const std::string& command) {
	commandName = command;
}

#endif