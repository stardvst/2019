#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "ctor" << std::endl;
	}
	operator unsigned long()
	{
		return 0;
	}
};

int main()
{
	A a;
	if (a == 0UL)
		std::cout << "a == 0UL" << std::endl;

	std::cin.get();
	return 0;
}