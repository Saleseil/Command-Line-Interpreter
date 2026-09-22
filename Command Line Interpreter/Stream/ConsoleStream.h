#ifndef CONSOLE_H
#define CONSOLE_H
#include "Stream.h"

//  Represents a console that interacts with the user.

class CommandLine;

class ConsoleStream : public Stream {
public:

	//	Returns the singleton instance of this class. Static. Singleton DP.
	static ConsoleStream* Insstance();

	//  Print the line in the console.
	virtual void print(const std::string& line);

	//  Start the console that interacts with the user.
	virtual void run();

	//  Set the command prompt.
	virtual void setPrompt(const std::string prompt);

	//  Read the text from console. 
	virtual std::string read();

protected:

	//  Constructor.
	ConsoleStream();

	//  Destroy the console.
	~ConsoleStream();

private:

	//  Command prompt.
	std::string promptr = "$";

	//  Command line that the user print in console.
	std::string line;

	//  Pointer to command line.
	CommandLine* commandline;

};

inline ConsoleStream::ConsoleStream() : commandline(nullptr) {}

inline void ConsoleStream::setPrompt(const std::string prompt) {
	this->promptr = prompt;
}

#endif
