#include <iostream>
#include <tuple>
#include <map>

int main()
{
	std::map<int, std::string> m;

	m.emplace(std::piecewise_construct,
		std::forward_as_tuple(10),
		std::forward_as_tuple(20, 'a'));

	// compile error
	//auto t = std::forward_as_tuple(20, 'a');
	//m.emplace(std::piecewise_construct, std::forward_as_tuple(10), t);

	std::cout << "m[10] = " << m[10] << '\n';

	std::cin.get();
}
