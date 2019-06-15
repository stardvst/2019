#include <iostream>

class Final;

class MakeFinal
{
private:
	MakeFinal()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	friend class Final;
};

class Final : public MakeFinal
{
public:
	Final()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};

class Derived : public Final
{
public:
	Derived()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};

int main()
{
	Derived d;
	std::cin.get();
	return 0;
}
