#include "Logger.h"
#include <iostream>
#include <ctime>
using namespace std;

Logger::Logger() {
}

// Setting the log level HIGH, MED, LOW
void Logger::setLogLevel(int newLogLevel) {
	logLevel = newLogLevel;
	string line = "\n___________________________________________________________\n\n";
	report << line << "***************  SETTING LOG LEVEL: " << levelStr[newLogLevel] << "  ***************\n" << endl;
}

// Logging any message into the report
void Logger::logInfo(string message) {
	report << "[INFO]: " << message << endl;
}

// Logging the Test Name to the report
void Logger::logTestName(string name, int testNumber) {
	string line = "___________________________________________________________\n";
	string title = "Running Test #" + to_string(testNumber) + ": " + name + "\n";
	report << line << title << line << endl;
}

// Logging the error message to the report
void Logger::logError(string error) {
	string dispMessage = "[ERROR]: ";
	dispMessage = dispMessage + error;
	report << dispMessage << endl;
}

void Logger::logException(string exception) {
	string dispMessage = "[EXCEPTION]: ";
	dispMessage = dispMessage + exception;
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