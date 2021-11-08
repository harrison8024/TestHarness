/////////////////////////////////////////////////////////////////////////
// TestManager.h													   //
// ver 1.0       The main test execution part of the Test Harness      //
//                                                                     //
// Language:      C++					                               //
// Application:   Project for CSE687 - Object Oriented Design          //
// Author:        Fang Wang, Syracuse University                       //
/////////////////////////////////////////////////////////////////////////

#include <string>
#include "ITest.h"
#include "Logger.h"
//#include "testfile.h"


class TestManager
{
	// Just a Template, everything is subject to change.
public:
	int logLevel;
	Logger logger;
	TestManager(int loglevel);

	bool performSingleTest(ITest &testObject);
	//void run(std::string dllPath);                   // entry function of the TestManager


};

