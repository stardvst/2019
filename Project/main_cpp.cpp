#include <iostream>
#include "list.h"

int main()
{

	List l;
	std::cout << "List is empty, size = " << l.size() << std::endl;

	std::cout << std::endl << "Adding elements..." << std::endl;
	l.push_back(2);
	l.push_front(7);
	l.push_front(8);
	l.push_back(4);
	l.push_front(3);
	l.push_back(6);
	l.insert(l.begin(), 1);

	std::cout << std::endl;
	for (node_wrapper nw = l.begin(); nw != l.end(); ++nw)
	{
		std::cout << *nw << " -> ";
	}
	std::cout << "NULL" << std::endl;
	std::cout << "size = " << l.size() << std::endl;

	std::cout << std::endl << "Removing element from front..." << std::endl;
	l.pop_front();
	for (node_wrapper nw = l.begin(); nw != l.end(); ++nw)
	{
		std::cout << *nw << " -> ";
	}
	std::cout << "NULL" << std::endl;
	std::cout << "size = " << l.size() << std::endl;

	std::cout << std::endl << "Removing element from back..." << std::endl;
	l.pop_back();
	for (node_wrapper nw = l.begin(); nw != l.end(); ++nw)
	{
		std::cout << *nw << " -> ";
	}
	std::cout << "NULL" << std::endl;
	std::cout << "size = " << l.size() << std::endl;

	std::cout << std::endl << "Removing 2nd element..." << std::endl;
	l.erase(++l.begin());
	for (node_wrapper nw = l.begin(); nw != l.end(); ++nw)
	{
		std::cout << *nw << " -> ";
	}
	std::cout << "NULL" << std::endl;
	std::cout << "size = " << l.size() << std::endl;

	std::cin.get();
	return 0;
}