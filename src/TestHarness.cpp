#include <iostream>
using std::cout;
using std::endl;

#include "Logger.h"

int main() {
	cout << "Test Harness is working..." << endl;
	cout << "Tony was here..." << endl;

	int testNum = 1;
	string testName = "High Voltage Test";
	string testInfo = "Voltage is tested at 200 Volts";
	string testError = "Voltage is too high";

	Logger log;
	log.logTestName(testName, testNum);
	log.logInfo(testInfo);
	log.logError(testError);
	log.logTime();

	testNum = 2;
	testName = "Continuity Test";
	testInfo = "Ampage is tested at 10 Amps";
	testError = "Amp is too low";

	log.logTestName(testName, testNum);
	log.logInfo(testInfo);
	log.logError(testError);
	log.logTime();
	
	cout << log.getReport();

}
