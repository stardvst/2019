#include <iostream>
#include "header.h"

void print(int n)
{
	std::cout << "n = " << n;
}

#define CALL_WITH_MAX(a, b) print((a) > (b) ? (a) : (b))

int main()
{
	std::cout << "from main: " << &globalStr;

	std::cout << "\nfrom f: ";
	f();

	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);
	std::cout << "\na = " << a << "\n";
	CALL_WITH_MAX(++a, b + 10);
	std::cout << '\n' << a << '\n';

	std::cin.get();
	return 0;
}
