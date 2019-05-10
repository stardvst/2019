#include <iostream>

int main()
{
	uint16_t numberA, numberB;
	numberA = 65535;
	numberB = numberA + 1;

	uint32_t numberC, numberD;
	numberC = 4294967295;
	numberD = numberC + 1;

	std::cout << numberA + 1 << '\n'; // output int
	std::cout << numberB << '\n'; // type is unsigned => 65536 is reduced to (65536 % 65536 = 0)

	std::cout << numberC + 1 << '\n';
	std::cout << numberD << '\n';

	std::cin.get();
	return 0;
}
