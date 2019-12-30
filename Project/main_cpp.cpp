#include <iostream>
#include <fstream>
#include <iterator>

struct NonMovable
{
	NonMovable(int)
	{
	}

	NonMovable(const NonMovable &) = delete;
	NonMovable(NonMovable &&) = delete;
};

NonMovable make()
{
	return NonMovable(42);
}

int main()
{
	auto largeObj = make();

	std::cin.get();
}