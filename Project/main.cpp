#include <iostream>

int main()
{
	char ch1 = 0;
	char ch2 = 0;
	char *p1 = &ch1;
	void *p2 = p1;

	int *p3 = static_cast<int *>(p2); // unsafe, legal C, not C++

	std::cout << ch1 << ' ' << ch2 << '\n';
	*p3 -= 1;
	std::cout << ch1 << ' ' << ch2 << '\n';

	std::cin.get();
}