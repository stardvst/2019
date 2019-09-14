#include <iostream>

int main()
{
	std::shared_ptr<int> int1 = std::make_shared<int>(100);
	std::weak_ptr<int> weak1(int1);
	const std::weak_ptr<int>& weak2(weak1);

	std::shared_ptr<int> orig = weak2.lock();

	std::cout << *orig << '\n';

	std::cin.get();
	return 0;
}