#include <string>
using namespace std;

class Logger
{
	// Just a Template, everything is subject to change.
public:
	int logLevel;
	string logFile;

	void logInfo();
	void logDetails();
	void logError();
	void logTime();
};

