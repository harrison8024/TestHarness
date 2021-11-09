#include "TestPerformer.h"
#include "TestManager.h"
#include "testfile.h"
#include "Logger.h"

int main() {

	// Initialize Classes
	TestManager testManager(Logger::LOW);
	Logger logger;

	// logLevel = LOW
	testfile mytest;
	testManager.performSingleTest(mytest);

	// logLevel = MEDIUM
	testManager.logLevel = Logger::MED;

	// logLevel = HIGH
	testManager.logLevel = Logger::HIGH;
}