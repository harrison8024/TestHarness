#include "Testable.h"

Testable::Testable(string testName, function<bool()> callable) {
	this->testName = testName;
	this->callable = callable;
}

bool Testable::test() {
	return callable();
}