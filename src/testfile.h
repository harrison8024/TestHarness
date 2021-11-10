#ifndef TESTFILE_H
#define TESTFILE_H

#include "ITest.h"

class testfile : public ITest {
public:
	testfile();

	virtual bool test(void) override;
};

#endif /* TESTFILE_H */