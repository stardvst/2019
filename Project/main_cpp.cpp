#include <iostream>

template <typename T>
auto getValue(T t)
{
	if constexpr (std::is_pointer_v<T>)
		return *t;
	else
		// must be in else case, otherwise both returns will be instantiated
		return t;
}

int main()
{
	int a = 5, *p = &a;
	std::cout << getValue(a) << ' ' << getValue(p);

	std::cin.get();
}