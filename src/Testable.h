#ifndef TESTABLE_H
#define TESTABLE_H

#include "ITest.h"
#include <string>
#include <functional>
#include <string>

using namespace std;

class Testable : public ITest {
public:
	string testName;
	function<bool()> callable;

	Testable(string testName, function<bool()> callable);
	bool test();
};

#endif /* TESTABLE_H */

