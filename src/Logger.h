#ifndef LOGGER_H
#define LOGGER_H

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

class Logger
{
	// Just a Template, everything is subject to change.
public:
	enum LogLevel { HIGH, MED, LOW }; // LOW = just pass/fail; MED = LOW + Failure Messages; HIGH = MED + Time stamp

	Logger(); // Logger constructor
	void setLogLevel(LogLevel);

	void logTestName(string, int);
	void logInfo(string);
	void logError(string);
	void logTime();


	
	string getReport();
	void clrReport();




private:
	LogLevel logLevel = LogLevel::HIGH; // log level determines how much info is recorded. Default to LOW which is just Pass/Fail
	stringstream report;
};

#endif