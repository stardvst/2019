#include <iostream>
#include <stack>

template <typename T>
struct MyContainer
{
	using value_type = T;
	using reference = T;
	using const_reference = T;
	using size_type = int;

	int size() const { return 356; }
};

int main()
{
	std::stack<int, MyContainer<int>> stack;

	std::cout << stack.size() << '\n';

	std::cin.get();
}
