
#include "TestManager.h"
#include <iostream>

TestManager::TestManager(int loglevel)
	:logLevel{ loglevel }, logger(loglevel) {}


bool TestManager::performSingleTest(ITest &testObject) {
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
		
	}
	catch (const std::exception& exc)
	{
		logger.logError("The test object failed the test due to exception:");
		logger.logError(exc.what());
		testResult = false;
	}

	return testResult;


}


//void TestManager::run(std::string dllPath) {
//	// get the test object using dllPath -> loadDll
//
//
//	// call performSingleTest
//}

