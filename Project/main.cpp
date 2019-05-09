#include <iostream>

int main()
{
	unsigned char age = 65;

	// prints garbage
	std::cout << age << '\n';
	std::cout << &age << '\n';

	// cast to a type that compiler doesn't interpret as characters
	std::cout << static_cast<unsigned>(age) << '\n';
	std::cout << static_cast<const void *>(&age) << '\n';

	std::cin.get();
	return 0;
}
