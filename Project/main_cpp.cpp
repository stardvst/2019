#include <iostream>

struct S
{
	S() { std::cout << "make an S\n"; }
	~S() { std::cout << "destroy an S\n"; }
};

int main()
{
	auto memory = (S *)malloc(sizeof S);
	new (memory) S();

	memory->~S();
	free(memory);

	std::cin.get();
}
