#include <iostream>

struct A
{
	~A()
	{
		throw 42;
	}
};

int main()
{
	try
	{
		A a;
		//throw 32;
	}
	catch (int a)
	{
		std::cout << a << '\n';
	}

	std::cin.get();
}
