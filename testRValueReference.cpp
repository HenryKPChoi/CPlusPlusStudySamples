#include <iostream>

class A{
public:
	enum
	{
		MaxSize = 256
	};

	explicit A(char * s) 
	{ 
		std::cout << "A()" << std::endl; 
		_ptr = new char[MaxSize];
		strcpy( _ptr, s );
	} 

	~A() 
	{ 
		if( NULL == _ptr )
			std::cout << "~A() : deleting NULL pointer " << std::endl; 
		else
			std::cout << "~A() : deleting 0x" << (void *)_ptr << std::endl; 

		delete _ptr;
	} 
	
	A(const A& a) 
	{
		std::cout << "Copy constructor " << std::endl;
		_ptr = new char[MaxSize];
		strcpy( _ptr, a._ptr);
	}

	A(A&& a) 
	{
		std::cout << "Copy constructor RVal" << std::endl;
		_ptr = a._ptr;
		a._ptr = NULL;
	}

	A& operator = (const A& a)
	{
		std::cout << "Assignment operator " << std::endl;
		_ptr = new char[MaxSize];
		strcpy( _ptr, a._ptr);		
		return *this;
	}
	A& operator = (A&& a)
	{
		std::cout << "Assignment operator RVal" << std::endl;
		_ptr = a._ptr;		
		a._ptr = NULL;
		return *this;
	}

	char * _ptr;
};

A func()
{
	A a("a from func()");
	return a;
}

void TestValueFromFunc()
{
	A a = func();
}

void TestMove()
{
	A a("test");
	A b = std::move(a);
}

void TestRValueRef()
{
	std::cout << "**** TestValueFromFunc ****" << std::endl;
	TestValueFromFunc();

	std::cout << "**** TestMove ****" << std::endl;
	TestMove();
}

int main(int argc, char* argv[])
{
	TestRValueRef();
	return 0;
}

