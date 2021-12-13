#ifndef LOGGER_H
#define LOGGER_H

#include "BlockingQueue.h"
#include <iostream>
#include <string>
#include <sstream>
#include <thread>


using namespace std;

class Logger
{
public:
	enum LogLevel {
		LOW,	// LOW = just pass/fail
		MEDIUM,	// MED = LOW + Failure Messages
		HIGH	// HIGH = MED + Time stamp
	};
	string levelStr[3] = {
		"LOW", 
		"MEDIUM",
		"HIGH"
	};
	Logger(); // Logger constructor
	~Logger(); // Logger Destructor

	void start();
	void stop(const std::string& msg = "");
	

	void setLogLevel(int);
	void logTestName(string name, int testNumber);
	void logInfo(string message);
	void logError(string error);
	void logException(string exception);
	void logTime();
	string getReport();

	void clrReport();

private:
	int logLevel = LOW; // log level determines how much info is recorded. Default to LOW which is just Pass/Fail
	stringstream report;
	bool threadRunning = false;
	BlockingQueue<string> _queue;
	std::thread* pThread;
	void write(const std::string& msg);
};

#endif /* LOGGER_H */
