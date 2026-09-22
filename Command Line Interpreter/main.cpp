#include "../Command Line Interpreter/Stream/ConsoleStream.h"
#include <iostream>

int main() {
	ConsoleStream* console = ConsoleStream::Insstance();
	console->run();
	return 0;
}