#ifndef VISITOR_H
#define VISITOR_H

//  Interface that checks if there is some errors in command line and commands.

class Visitor {
public:

	//  Process if there is something wrong with syntax and lexical rules in command line and commands.
	virtual void proccesException() = 0;

};



#endif 