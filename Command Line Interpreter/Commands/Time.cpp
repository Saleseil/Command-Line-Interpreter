#include "Time.h"
#include "../Visitors/VisitTime.h"
#include <ctime>


Time::Time(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Time::checkCommand() {
	VisitCommand = new VisitTime(this);
	VisitCommand->proccesException();
}

void Time::execute() {
	std::string line;
	std::time_t currentTime = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	std::string h = std::to_string(localTime.tm_hour);
	std::string m = std::to_string(localTime.tm_min);
	std::string s = std::to_string(localTime.tm_sec);
	if (h.length() < 2) h = '0' + h;
	if (m.length() < 2) m = '0' + h;
	if (s.length() < 2) s = '0' + s;

	line = line + h + ':' + m + ':' + s;
	setoutputline(line);
}
