#include <iostream>

template <typename... Ts>
using void_t = void;

template <typename T, typename = void>
struct has_typedef : std::false_type {};

template <typename T>
struct has_typedef<T, void_t<typename T::foobar>> : std::true_type {};

struct foo
{
	using foobar = float;
};

int main()
{
	std::cout << std::boolalpha;
	std::cout << has_typedef<int>::value << '\n';
	std::cout << has_typedef<foo>::value << '\n';

	std::cin.get();
	return 0;
}
