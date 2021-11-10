#ifndef TEST_OBJECTS_H
#define TEST_OBJECTS_H

#include <stdexcept>

class Base { virtual void member() {} };
class Derived : Base {};

// Polymorphic struct so we can throw a bad_typeid.
// This type of exception is thrown each time a typeid is applied
// to a dereferenced null pointer value of polymorphic type.
struct BadStruct { virtual void BadStructFuction(); };

// Functions for throwing a bad_exception
void throw_e();
void test_throw_e() throw(std::bad_exception);

bool TestTrue();
bool TestFalse();
bool TestBadAlloc();
bool TestBadCast();
bool TestBadException();
bool TestBadTypeID();
bool TestBadFunctionCall();
bool TestBadWeakPtr();
bool TestAdd();
bool TestAllocate();

#endif /* TEST_OBJECTS_H */