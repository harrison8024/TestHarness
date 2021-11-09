#include "Logger.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <sstream>
using std::stringstream;

#include <ctime>
using std::time_t;

Logger::Logger() {
}

// Setting the log level HIGH, MED, LOW
void Logger::setLogLevel(LogLevel newLogLevel) {
	logLevel = newLogLevel;
}

// Logging any message into the report
void Logger::logInfo(string message) {
	report << message << endl;
}

// Logging the Test Name to the report
void Logger::logTestName(string name, int testNumber) {
	string dispMessage = "___________________________________________________________\n  Running Test #" + to_string(testNumber) + ": " + name + "\n___________________________________________________________\n";
	report << dispMessage << endl;
}

// Logging the error message to the report
void Logger::logError(string error) {
	string dispMessage = "Error Message: ";
	dispMessage = dispMessage + error;
	report << dispMessage << endl;
}

// Logging the time stamp into the report
void Logger::logTime() {
	time_t now = time(0);
	string dateTime = ctime(&now);
	report << dateTime << endl;
}

// Displays the report into the console
string Logger::getReport() {
	cout << "Test Log: \n";
	string returnReport = report.str();
	return returnReport;
}

// Clears the report
void Logger::clrReport() {
	report.str(string());
}




// Overload log method
//void Logger::log(bool pass, string error) {
//	string logString = "";
//	time_t now = time(0);
//	string dateTime = ctime(&now);
//
//	// Log Level LOW: Only Display Test Pass or Fail.
//	if (pass) {
//		logString = "Test Passed.	\n";
//	}
//	else {
//		logString = "Test Failed.	\n";
//	}
//
//	// Log Level MED: LOW + Error Message
//	if ((logLevel == MED || logLevel == HIGH) && !pass) {
//		logString = logString + "Error Message:  " + error; 
//	}
//
//	// Log Level HIGH: MED + TimeStamp
//	if (logLevel == HIGH) {
//		logString = logString + "Date / Time: " + dateTime;
//	}
//
//	report << logString << endl;
//}
