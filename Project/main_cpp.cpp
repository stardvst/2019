#include <iostream>
#include <typeinfo>

int main()
{
	auto x{ 1 };
	std::cout << typeid(x).name() << std::endl;
	std::cin.get();
}
