#include <iostream>
#include <tuple>
#include <string>

template <typename T>
T adder(T v)
{
	return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args)
{
	return first + adder(args...);
}

template <typename... Args>
auto foldAdder(Args... args)
{
	std::cout << __FUNCSIG__ << '\n';
	return (args + ...);
}

int main()
{
	std::cout << adder(4, 5, 6) << '\n';
	std::cout << foldAdder<int>(4, 5, 6) << '\n';

	std::cin.get();
}
