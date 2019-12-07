#include <iostream>
#include <tuple>

struct Foo
{
	Foo(std::tuple<int, float>)
	{
		std::cout << "Foo from tuple\n";
	}
	Foo(int, float)
	{
		std::cout << "Foo from int and float\n";
	}
};

int main()
{
	std::tuple<int, float> t(1, 3.14);
	std::pair<Foo, Foo> p1(t, t);
	std::pair<Foo, Foo> p2(std::piecewise_construct, t, t);

	std::cin.get();
}
