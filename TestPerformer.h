#include <string>
using namespace std;

class TestPerformer
{
	// Just a Template, everything is subject to change.
public:
	int logLevel;
	int TestArr;
	int ResultArr;

	void loadTestFile();
	void displayResult();
	void executeTest();
};

