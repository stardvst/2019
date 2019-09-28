#include <iostream>

struct S {};
struct W : private S { int a; };
struct T { S s; };

int main()
{
	std::cout << sizeof(S) << '\n';
	std::cout << sizeof(W) << '\n';
	std::cout << sizeof(T);

	std::cin.get();
}
