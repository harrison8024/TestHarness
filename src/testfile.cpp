#include "testfile.h"

using std::cout;

testfile::testfile() {}
bool testfile::test(void) {
	cout << "[testfile] test start.. \n";
	cout << "[testfile] test pass\n";
	//throw("I'm dead");
	return false;
}