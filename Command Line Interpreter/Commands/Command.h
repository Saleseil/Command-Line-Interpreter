#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include "../Exceptions/ErrorLine.h"

//	Abstract generalization of all commands.

class CommandLine;

class VisitCommand;

class ConsoleStream;

class InputFileStream;

class OutputFileStream;

class Command : public ErrorLine{
public:

	Command(const std::string& commandName, CommandLine* commLine);
	
	//  Destroy the visitor and input-output file streams.
	virtual ~Command();

	//  Checks the syntax rules for command with visitor.
	virtual void checkCommand() = 0;

	//  Execute the command.
	virtual void execute() = 0;

	//  Read the input line from input stream (Some commands can have different input flow).
	virtual void inputFlow();

	//  Send the result of command to output stream (Some commands can have different output flow).
	virtual void outputFlow();

	//  Print the errors in the console.
	virtual void printError();

	//  Check if there is a output redirection in command.
	virtual bool checkoutredirection();

	//  Returns input line of command.
	virtual std::string& getinputline();

	//  Returns result of command.
	virtual std::string& getoutputline();

	//  Sets result of command.
	virtual void setoutputline(const std::string& line);

	//  Sets input line of command.
	virtual void setinputline(const std::string& line);

	//  Returns the name of command.
	virtual std::string& getname();

	//  Returns the option argument of command (if exist).
	virtual std::string* getopt();

	//  Returns the list of arguments of command.
	virtual std::vector<std::string>& getArguments();

	//  Returns the command line.
	virtual CommandLine* getCommandLine();

	//  Returns the number of optional arguments.
	virtual int getnumOptArguments();

	virtual void addArgument(const std::string& argument);

	//  Pointer to the next command in list.
	Command* next;

	//  Pointer to command visitor.
	VisitCommand* VisitCommand;
	
	//  Pointer to the console. 
	ConsoleStream* clsStream;

	//  Pointer to the input file stream.
	InputFileStream* inputFileStream;

	//  Pointer to output file stream.
	OutputFileStream* outputFileStream;


protected:

	//  Sets the name of command..
	virtual void setname(const std::string& name);

	//  Sets the list of arguments of command.
	virtual void setArguments(const std::vector<std::string>& arguments);
	
	//  Process input flow from commmand argument that has a double quotes.  
	virtual void inputFromQuotes(const std::string& argument);

	//  Process input flow from console.
	virtual void inputFromConosle();

	//  Process input flow from file.
	virtual void inputFromFile(const std::string& argument);

	//  Send a result of command in the console.
	virtual void outputInConsole(const std::string& line);

	//  Send a result of command in the file.
	virtual void outputInFile(const std::string& argument);

private:

	//  Pointer to command line which created the command.
	CommandLine* commandLine;

	//  Name of the command.
	std::string name;

	//  List of command arguments.
	std::vector<std::string> arguments;

	//  Text that command read from input stream.
	std::string inputline;

	//  Result that command send in output stream.
	std::string outputline;

};

inline void Command::setoutputline(const std::string& line) {
	this->outputline = line;
}

inline void Command::setinputline(const std::string& line) {
	this->inputline = line;
}

inline void Command::setname(const std::string& name) {
	this->name = name;
}

inline std::string& Command::getoutputline() {
	return outputline;
}

inline std::string& Command::getname() {
	return name;
}

inline void Command::setArguments(const std::vector<std::string>& arguments) {
	this->arguments = arguments;
}

inline std::vector<std::string>& Command::getArguments() {
	return arguments;
}

inline std::string& Command::getinputline() {
	return inputline;
}

inline CommandLine* Command::getCommandLine() {
	return commandLine;
}

inline void Command::addArgument(const std::string& argument) {
	arguments.push_back(argument);
}

#endif 

