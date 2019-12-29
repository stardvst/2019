#include <iostream>
#include <functional>

struct abc
{
	void f(int)
	{
		std::cout << __FUNCSIG__ << std::endl;
	}

	void f(int) const
	{
		std::cout << __FUNCSIG__ << std::endl;
	}
};

int main()
{
	const abc x;
	int a = 1;

	// need to cast
	using fptr = void (abc:: *)(int) const;
	// pass x by ref otherwise won't compile
	std::bind((fptr)&abc::f, std::cref(x), std::placeholders::_1)(a);

	// or just
	std::bind<void (abc:: *)(int) const>(&abc::f, std::cref(x), std::placeholders::_1)(a);

	std::cin.get();
}