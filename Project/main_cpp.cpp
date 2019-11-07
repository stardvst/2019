#include <iostream>

template <typename T>
bool pair_comparer(T a)
{
	return false;
}

template <typename T>
bool pair_comparer(T a, T b)
{
	return a == b;
}

template <typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args)
{
	return a == b && pair_comparer(args...);
}

int main()
{
	std::cout << "compare (1.5, 1.5, 2, 2, 6, 6): " << std::boolalpha << pair_comparer(1.5, 1.5, 2, 2, 6, 6) << '\n';

	// double == int: compile error
	//std::cout << "compare (1.5, 1, 2, 2, 6, 6): " << std::boolalpha << pair_comparer(1.5, 1, 2, 2, 6, 6) << '\n';

	// odd number of args: compile error
	std::cout << "compare (1.5, 1.5, 2, 2, 6, 6, 7): " << std::boolalpha << pair_comparer(1.5, 1.5, 2, 2, 6, 6, 7) << '\n';

	std::cin.get();
}
