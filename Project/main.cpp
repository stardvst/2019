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
	f<int>(10); // no int::foo, but doesn't fail because 2nd function is used

	std::cin.get();
}
