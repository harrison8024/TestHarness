#include <iostream>
using std::cout;
using std::endl;

#include "Logger.h"

int main() {
	cout << "Test Harness is working..." << endl;
	cout << "Tony was here..." << endl;

	// Initialize Variables
	Logger Log;
	bool Pass;
	string errorMessage = "";

	// Test Logger level LOW that passes.
	Log.setLogLevel(Logger::LOW);
	bool pass = 0;
	Log.log(pass, errorMessage);

	// Test Logger level LOW that Fails.
	Log.setLogLevel(Logger::LOW);
	bool pass = 1;
	errorMessage = "This Test Failed.";
	Log.log(pass, errorMessage);

	Log.getReport();
}