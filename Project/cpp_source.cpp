#include <iostream>

template <typename T>
struct has_typedef
{
	using yes = char[1];
	using no = char[2];

	template <typename C>
	static yes &test(typename C::foobar *);

	template <typename C>
	static no &test(...);

	static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

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
