#include <string>
#include <iostream>
using namespace std;

class Logger
{
	// Just a Template, everything is subject to change.
public:
	int logLevel;
	//string logFile;

	Logger(int loglevel);
	void logInfo(string message);
	void logDetails(string message);
	void logError(string message);
	void logTime();
};

