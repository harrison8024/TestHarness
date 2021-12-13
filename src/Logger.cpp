#include "Logger.h"
#include <iostream>
#include <ctime>
#include <functional>
#include <Windows.h>


using namespace std;


Logger::Logger() {
}

// Setting the log level HIGH, MED, LOW
void Logger::setLogLevel(int newLogLevel) {
	logLevel = newLogLevel;
	string line = "\n___________________________________________________________\n\n";
	report << line << "***************  SETTING LOG LEVEL: " << levelStr[newLogLevel] << "  ***************\n" << endl;
}

// Logger Destructor
Logger::~Logger()
{
	stop();
}

// Logging any message into the report
void Logger::logInfo(string message) {
	string info = "[INFO]: " + message + "\n";
	//report << info << endl;
	write(info);
}

// Logging the Test Name to the report
void Logger::logTestName(string name, int testNumber) {
	string line = "___________________________________________________________\n";
	string title = "Running Test #" + to_string(testNumber) + ": " + name + "\n";
	string testName = line + title + line;
	//report << testName << endl;
	write(testName);
}

// Logging the error message to the report
void Logger::logError(string error) {
	string dispMessage = "[ERROR]: ";
	dispMessage = dispMessage + error;
	//report << dispMessage << endl;
	write(dispMessage);
}

void Logger::logException(string exception) {
	string dispMessage = "[EXCEPTION]: ";
	dispMessage = dispMessage + exception + "\n";
	//report << dispMessage << endl;
	write(dispMessage);
}

// Logging the time stamp into the report
void Logger::logTime() {
	time_t now = time(0);
	string dateTime = ctime(&now);
	dateTime = dateTime + "\n";
	//report << dateTime << endl;
	write(dateTime);
}

void Logger::write(const std::string& msg)
{
	if (threadRunning)
		_queue.enQ(msg);
}

// Displays the report into the console
string Logger::getReport() {
	cout << "\nTest Log: \n";
	string returnReport = report.str();
	return returnReport;
}

// Clears the report
void Logger::clrReport() {
	report.str(string());
}

// Start Logging
void Logger::start()
{
	if (threadRunning)
		return;
	threadRunning = true;
	std::function<void()> tp = [=]() {
		while (true)
		{
			std::string msg = _queue.deQ();
			if (msg == "quit")
			{
				threadRunning = false;
				break;
			}
			report << msg;
		}
	};
	std::thread thr(tp);
	thr.detach();
}

// Stop Logging
void Logger::stop(const std::string& msg)
{
	if (threadRunning)
	{
		if (msg != "")
			write(msg);
		write("quit");  // request thread to stop
		while (threadRunning)
			/* wait for thread to stop*/
			;
	}
}