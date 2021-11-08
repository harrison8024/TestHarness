#include "ITest.h"

class testfile : public ITest {
public:
	testfile();

	virtual bool test(void) override;

};