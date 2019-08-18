#include <iostream>

struct Test
{
	using foo = int;
};

template <typename T>
void f(typename T::foo) {}

template <typename T>
void f(T) {}

int main()
{
	f<Test>(10);
	f<int>(10);

	std::cin.get();
	return 0;
}
