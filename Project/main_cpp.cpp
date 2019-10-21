#include <iostream>

template <typename T>
struct remove_ref
{
	using type = T;
};

template <typename T>
struct remove_ref<T &>
{
	using type = T;
};

template <typename T>
struct remove_ref<T &&>
{
	using type = T;
};

template <typename T>
typename remove_ref<T>::type &&myMove(T &&o)
{
	return static_cast<typename remove_ref<T>::type &&>(o);
}

struct A
{
	A() {}
	A(const A &) { std::cout << "copy\n"; }
	A &operator=(const A &) { std::cout << "assign\n"; return *this; }
	A(A &&) noexcept { std::cout << "move\n"; }
};

int main()
{
	A a;
	//A b = std::move(a);
	A b = myMove(a);

	std::cin.get();
}
