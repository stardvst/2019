#include <iostream>
#include <vector>

class SomeClass
{
public:
	static int getValue()
	{
		return value;
	}

private:
	static int value;
};

int SomeClass::value;

int main()
{
	std::cout << SomeClass::getValue() << std::endl;

	system("pause");
}
