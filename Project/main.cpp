#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8 };

	// erase a few items
	vec.erase(std::find(vec.cbegin(), vec.cend(), 4));
	vec.erase(std::find(vec.cbegin(), vec.cend(), 7));

	// print all items
	for (auto item : vec)
		std::cout << item << '\n';

	// prints 1 2 3 5 6 8

	system("pause");
}
