#include <iostream>
#include <vector>

std::vector<int> reverse(int i)
{
	return std::vector<int> {i};
}

template <typename... Ts>
std::vector<int> reverse(int i, Ts... ts)
{
	auto v = reverse(ts...);
	v.push_back(i);
	return v;
}

int main()
{
	for (const auto &i : reverse(1, 2, 3, 4))
		std::cout << i << ' ';

	std::cin.get();
}
