#include "TestManager.h"
#include "Logger.h"
#include <iostream>

TestManager::TestManager(int loglevel) {
	this->logLevel = loglevel;
	logger.setLogLevel(loglevel);
}

bool TestManager::performSingleTest(Testable& testObject) {
	logger.logTestName(testObject.testName, testCounter++);
	logger.logInfo("Perform the single test.");
	bool testResult;

	try
	{
		testResult = testObject.test();
		if (testResult) {
			logger.logInfo("The test object passed the test.");
		}
		else {
			logger.logError("The test object failed the test!");
		}
		logger.logTime();
	}
	catch (const std::exception& exc)
	{
		logger.logError("The test object failed the test due to exception:");
		logger.logError(exc.what());
		testResult = false;
	}

	std::cout << logger.getReport();
	return testResult;
}