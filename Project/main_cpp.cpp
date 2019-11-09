#include <iostream>
#include "set.h"

int main()
{
	set s;

	s.insert(10);
	s.insert(8);
	s.insert(9);

	for (node_wrapper nw = s.begin(); nw != s.end(); ++nw)
	{
		std::cout << *nw << " ";
	}
	std::cout << std::endl << std::endl;

	for (node_wrapper nw = s.rbegin(); nw != s.rend(); --nw)
	{
		std::cout << *nw << " ";
	}
	std::cout << std::endl;

	std::cin.get();
	return 0;
}