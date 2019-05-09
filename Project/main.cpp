#include <iostream>

template <typename T>
auto promoteToPrintableIntegerType(T i) -> decltype(+i)
{
	return +i;
}

int main()
{
	unsigned char age = 65;

	std::cout << promoteToPrintableIntegerType(age) << '\n';

	std::cin.get();
	return 0;
}
