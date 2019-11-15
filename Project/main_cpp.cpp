#include <iostream>
#include <vector>

void push(std::vector<int> &v, int value)
{
	// will avoid reallocation
	if (v.capacity() <= v.size())
	{
		std::cout << "inserting " << value << "..., but first, capacity: " << v.capacity() << std::endl;
		v.reserve(v.size() * 1.1);
		std::cout << "capacity after resize: " << v.capacity() << std::endl;
	}

	// will always be the same, contrary to if we used push_back() without reserve()
	std::cout << "element addresses:\n";
	for (const auto &a : v)
		std::cout << &a << '\n';

	std::cout << '\n';

	v.push_back(value);
}

int main()
{
	std::vector<int> v;

	push(v, 5);
	push(v, 3);
	push(v, 6);
	push(v, 7);
	push(v, 1);
	push(v, 2);
	push(v, 4);

	std::cin.get();
	return 0;
}