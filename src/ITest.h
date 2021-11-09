/////////////////////////////////////////////////////////////////////////
// ITest.h															   //
// history		  was declared as interface testale                    //
//				  then change to ITest								   //
// ver 2.0        An ITest interface that declares a test method       //
//                taking no arguments and returning a boolean value    //
//				  indicating test pass or failure                      //
// Language:      C++					                               //
// Application:   Project for CSE687 - Object Oriented Design          //
// Author:        Fang Wang, Syracuse University                       //
/////////////////////////////////////////////////////////////////////////
#ifndef ITEST_H
#define ITEST_H

#ifdef TEST_EXPORTS
#define TEST_API __declspec(dllexport)
#else
#define TEST_API __declspec(dllimport)
#endif

#include <iostream>
class ITest {
public:
	virtual ~ITest() {};
	virtual bool test() = 0;
};

#endif /* ITEST_H */
