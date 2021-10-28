#include "TestPerformer.h"
#include <iostream>
using namespace std;


TestPerformer::TestPerformer()
{
	logLevel = LOW;
}

TestPerformer::~TestPerformer()
{
}

void TestPerformer::setLogLevel(int level)
{
	logLevel = level;
}

void TestPerformer::executeTest(function<void()> callable)
{
	try
	{
		callable();

		cout << "Pass" << endl;
	}
	catch(exception &e)
	{
		cout << "Fail " << e.what() <<endl;
	}
	catch (...)
	{
		cout << "Fail " << "Unknow Exception" << endl;
	}
}