#ifndef TESTPERFORMER_H
#define TESTPERFORMER_H


#include <string>
#include <functional>
using namespace std;

class TestPerformer
{
	// Just a Template, everything is subject to change.
public:
	enum LogLevel{LOW, MEDIUM, HIGH};
	int logLevel;

	TestPerformer();
	~TestPerformer();
	void setLogLevel(int level);
	void executeTest(function<void()> callable);
};

#endif // TESTPERFORMER_H