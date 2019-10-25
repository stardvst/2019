#include <iostream>

void my_term_handler()
{
	std::cout << __FUNCTION__ << '\n';
}

struct A
{
	~A()
	{
		throw 42;
	}
};

int main()
{
	std::set_terminate(my_term_handler);

	try
	{
		A a;
		throw 32;
	}
	catch (int a)
	{
		std::cout << a << '\n';
	}

	std::cin.get();
}
