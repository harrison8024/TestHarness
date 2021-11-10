#include "TestManager.h"
#include "Logger.h"
#include <iostream>

TestManager::TestManager(int loglevel) {
	logLevel = loglevel;
	logger.setLogLevel(loglevel);
}

bool TestManager::performSingleTest(Testable& testObject) {
	logger.logTestName(testObject.testName, testCounter++);
	bool testResult;

	try
	{
		testResult = testObject.test();
		if (testResult) {
			logger.logInfo("Passed Test!");
		}
		else {
			logger.logError("Failed Test!");
		}
	}
	catch (const std::exception& exc)
	{
		logger.logError("Failed Test!");
		if (logLevel > Logger::LOW) {
			logger.logException(exc.what());
		}
		testResult = false;
	}
	if (logLevel == Logger::HIGH) {
		logger.logTime();
	}
	return testResult;
}