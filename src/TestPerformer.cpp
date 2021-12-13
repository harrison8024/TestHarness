#include "TestPerformer.h"
#include "TestManager.h"
#include "Logger.h"
#include "Testable.h"
#include "TestObjects.h"

int main() {


	Logger log;
	log.logInfo("\n  Hello Logging Info 1. Should not be logged...");		// Should not be logged because have not started yet
	log.logTestName("Should not be logged....", 1);							// Should not be logged because have not started yet
	log.start();
	log.logTestName("Testing Logger", 1);
	log.logInfo("Hello Logging Info 2");
	log.logError("Logging Error 1");
	log.stop();
	log.logError("\n  Logging Error 2. Should not be logged...");			// Should not be logged because have not started yet
	log.logException("\n  Logging Exception 1. Should not be logged...");	// Should not be logged because have not started yet
	log.start();
	log.logException("Logging Exception 2.\n");
	log.logInfo("Logging Info 3");
	log.stop("\n  terminating now");

	std::cout << log.getReport();
	log.clrReport();
	std::cout << log.getReport();

	//// Initialize Classes
	//TestManager testManager(Logger::LOW);

	//// Load Testables
	//Testable t1("Test True", TestTrue);
	//Testable t2("Test False", TestFalse);
	//Testable t3("Test Bad Allocation", TestBadAlloc);
	//Testable t4("Test Bad Cast", TestBadCast);
	//Testable t5("Test Bad Type ID", TestBadTypeID);
	//Testable t6("Test Bad Weak Pointer", TestBadWeakPtr);
	//Testable t7("Test Bad Function Call", TestBadFunctionCall);
	//Testable t8("Test Bad Exception", TestBadException);
	//Testable t9("Test Add", TestAdd);
	//Testable t10("Test Allocation", TestAllocate);

	//// logLevel = LOW
	//testManager.performSingleTest(t1);
	//testManager.performSingleTest(t2);
	//testManager.performSingleTest(t3);
	//testManager.performSingleTest(t4);
	//testManager.performSingleTest(t5);
	//testManager.performSingleTest(t6);
	//testManager.performSingleTest(t7);
	//testManager.performSingleTest(t8);
	//testManager.performSingleTest(t9);
	//testManager.performSingleTest(t10);


	//// logLevel = MEDIUM
	//testManager.logLevel = Logger::MEDIUM;
	//testManager.logger.setLogLevel(Logger::MEDIUM);

	//testManager.performSingleTest(t1);
	//testManager.performSingleTest(t2);
	//testManager.performSingleTest(t3);
	//testManager.performSingleTest(t4);
	//testManager.performSingleTest(t5);
	//testManager.performSingleTest(t6);
	//testManager.performSingleTest(t7);
	//testManager.performSingleTest(t8);
	//testManager.performSingleTest(t9);
	//testManager.performSingleTest(t10);

	//// logLevel = HIGH
	//testManager.logLevel = Logger::HIGH;
	//testManager.logger.setLogLevel(Logger::HIGH);

	//testManager.performSingleTest(t1);
	//testManager.performSingleTest(t2);
	//testManager.performSingleTest(t3);
	//testManager.performSingleTest(t4);
	//testManager.performSingleTest(t5);
	//testManager.performSingleTest(t6);
	//testManager.performSingleTest(t7);
	//testManager.performSingleTest(t8);
	//testManager.performSingleTest(t9);
	//testManager.performSingleTest(t10);

	//std::cout << testManager.logger.getReport();

}