#include "TestObjects.h"
#include <iostream>
#include <functional>

bool TestTrue()
{
	return true;
}

bool TestFalse()
{
	return false;
}

bool TestAllocate()
{
	std::cout << "TestAllocate \n";
	int* foo;
	foo = new int[10];
	return true;
}

bool TestAdd()
{
	std::cout << "TestAdd \n";
	int i, j;
	i = 1;
	j = 2;
	j = j + i;
	return true;
}

bool TestBadAlloc()
{
	std::bad_alloc x;
	std::cout << "TestBadAlloc \n";
	while (true)
	{
		new int[100000000ul];
	}
	throw x;
	return true;
}

// Test case for bad casting. A dervied class
// should never be dynamically casted back to a base
// class.
bool TestBadCast()
{
	std::bad_cast e;
	std::cout << "TestBadCast \n";
	Base b;
	Derived& rd = dynamic_cast<Derived&>(b);
	throw e;
	return true;
}

void throw_e() { throw; }
void test_throw_e() throw(std::bad_exception)
{
	throw std::runtime_error("Error");
}

bool TestBadException()
{
	std::bad_exception e;
	std::cout << "TestBadException \n";
	std::set_unexpected(throw_e);
	test_throw_e();
	throw e;
	return true;
}

bool TestBadTypeID()
{
	std::bad_typeid e;
	std::cout << "TestBadTypeID \n";
	BadStruct* ptr = nullptr;
	std::cout << typeid(*ptr).name() << '\n';
	throw e;
	return true;
}

bool TestBadFunctionCall()
{
	std::bad_function_call e;
	std::cout << "TestBadFunctionCall \n";
	std::function<int()> TestBadFunction = nullptr;
	TestBadFunction();
	throw e;
	return true;
}

bool TestBadWeakPtr()
{
	std::bad_weak_ptr e;
	std::cout << "TestBadWeakPtr \n";
	std::shared_ptr<int> p1(new int(100));
	std::weak_ptr<int> wp(p1);
	p1.reset();
	throw e;
	return true;
}