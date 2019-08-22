#include <iostream>
#include <limits>
#include <algorithm>

int main()
{
	int x = 10;
	int y = 10;

	const int &max = std::max(x, y);
	const int &min = std::min(x, y);

	x = 11;
	y = 9;

	std::cout << max << min;
	
	std::cin.get();
	return 0;
}
