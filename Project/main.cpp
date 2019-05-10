#include <iostream>

int main()
{
	char a = 30, b = 40, c = 10;
	char d = (a * b) / 10; // integer promotion
	std::cout << +d;

	std::cin.get();
	return 0;
}
