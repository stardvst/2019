#include <iostream>

struct S
{
	S() { std::cout << "make an S\n"; }
	~S() { std::cout << "destroy an S\n"; }
	S(const S &) { std::cout << "copy init an S\n"; }
	S &operator=(const S &) { std::cout << "copy assign an S\n"; }
};

S *getRawS()
{
	return new S;
}

std::unique_ptr<S> getUniquePtrS()
{
	return std::make_unique<S>();
}

int main()
{
	std::cout << "start main\n";
	S *rawS = getRawS();

	std::cout << "after raw, before smart pointer\n";
	std::unique_ptr<S> smartS = getUniquePtrS();

	std::cout << "exit main\n";

	// leaks rawS
	// implicitly deletes smartS

	std::cin.get();
}
