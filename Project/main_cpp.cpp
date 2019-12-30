#include <iostream>
#include <utility>

void f(std::pair<int, int>)
{
}

int main()
{
	f(std::pair(42, 42));

	std::cin.get();
}