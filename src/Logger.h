#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <sstream>
using namespace std;

class Logger
{
public:
	enum LogLevel { HIGH, MED, LOW }; // LOW = just pass/fail; MED = LOW + Failure Messages; HIGH = MED + Time stamp

	Logger(); // Logger constructor
	void setLogLevel(int);

	void logTestName(string, int);
	void logInfo(string);
	void logError(string);
	void logTime();

	string getReport();
	void clrReport();

private:
	int logLevel = HIGH; // log level determines how much info is recorded. Default to LOW which is just Pass/Fail
	stringstream report;
};

#endif /* LOGGER_H */