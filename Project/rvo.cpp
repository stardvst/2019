#include <iostream>

struct X
{
	X()
	{
		std::cout << "X::X()\n";
	}

	X(const X &)
	{
		std::cout << "X::X(const X &)\n";
	}

	X(X &&)
	{
		std::cout << "X::X(X &&)\n";
	}
};

X good()
{
	std::cout << __FUNCTION__ << '\n';
	X x;
	return x;
}

X bad()
{
	std::cout << __FUNCTION__ << '\n';
	X x;
	return std::move(x);
}

int main()
{
	auto x1 = good();
	auto x2 = bad();

	std::cin.get();
}
