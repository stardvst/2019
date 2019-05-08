#include <iostream>

struct Fred
{
	int a;
};

int main()
{
	Fred x;
	std::cout << x.a << std::endl;

	std::cin.get();
	return 0;
}
