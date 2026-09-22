#include "Date.h"
#include "../Visitors/VisitDate.h"
#include <ctime>

Date::Date(const std::string& name, CommandLine* commLine) : Command(name, commLine) {}

void Date::checkCommand() {
	VisitCommand = new VisitDate(this);
	VisitCommand->proccesException();
}

void Date::execute() {
	std::string line;
	std::time_t currentTime = std::time(nullptr);
	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	std::string y = std::to_string(localTime.tm_year + 1900);
	std::string m = std::to_string(localTime.tm_mon + 1);
	std::string d = std::to_string(localTime.tm_mday);
	if (m.length() < 2) m = '0' + m;
	if (d.length() < 2) d = '0' + d;

	line = line + d + '.' + m + '.' + y;
	setoutputline(line);
}
