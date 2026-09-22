#ifndef STREAM_H
#define STREAM_H
#include <string>

//  Interface that applies to all input and output streams.

class Stream {
public:

	//  Print the line in the stream output.
	virtual void print(const std:: string& line) = 0;

	//  Read the line from stream input.
	virtual std::string read() = 0;

};

#endif 

