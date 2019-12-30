#include <iostream>
#include <map>

int main()
{
	std::map<int, int> m{ { 1, 2 }, { 2, 3 }, { 3, 4 } };

	for (const auto &[k, v] : m)
		std::cout << k << " -> " << v << '\n';

	std::cin.get();
}