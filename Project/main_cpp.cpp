#include <iostream>

auto sumCpp11()
{
	return 0;
}

template <typename T, typename... Args>
auto sumCpp11(T v, Args... vs)
{
	return v + sumCpp11(vs...);
}

template <typename ...Args>
auto sumCpp17(Args ...args)
{
	//return (args + ... + 0);
	return (args + ...);
}

template <typename ...Args>
void foldPrint(Args &&...args)
{
	(std::cout << ... << std::forward<Args>(args)) << '\n';
}

int main()
{
	std::cout << sumCpp11(1, 2, 3) << '\n';
	foldPrint(sumCpp17(1, 2, 3));

	std::cin.get();
}