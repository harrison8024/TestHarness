#include "Logger.h"

Logger::Logger(int loglevel)
	:logLevel(loglevel)
{}


void Logger::logInfo(string message)
{
	std::cout << message << endl;
}


void Logger::logDetails(string message)
{
	std::cout << message << endl;
}


void Logger::logError(string message)
{
	std::cout << message << endl;
}



