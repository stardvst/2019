#include <iostream>

//////////////////////////////////////////////////////////////////////////

template <typename T>
void foo(T x, std::true_type)
{
	std::cout << "Primitive type\n";
}

template <typename T>
void foo(T x, std::false_type)
{
	std::cout << "Not a primitive type\n";
}

template <typename T>
void foo(T x)
{
	foo(x, std::is_fundamental<T>{});
}

//////////////////////////////////////////////////////////////////////////

template <typename T, typename flag = typename std::is_fundamental<T>::type>
struct C;

template <typename T>
struct C<T, std::true_type>
{
	C(T t) : x(t)
	{
	}

	T x;

	void foo()
	{
		std::cout << "Primitive type\n";
	}
};

template <typename T>
struct C<T, std::false_type>
{
	C(T t) : x(t)
	{
	}

	T x;

	void foo()
	{
		std::cout << "Not a primitive type\n";
	}
};

int main()
{
	struct A {};

	foo(5);
	foo(A());

	C<int> c1(3);
	c1.foo();
	C<A> c2{ A() };
	c2.foo();

	std::cin.get();
}
