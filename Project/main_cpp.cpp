#include <iostream>
#include <vector>
#include <list>
#include <set>

template <template <typename, typename> typename CT, typename VT, typename AT>
void foo(const CT<VT, AT> &cont)
{
	for (const auto &it : cont)
		std::cout << it << '\n';
	std::cout << "----\n";
}

template <template <typename, typename...> typename CT, typename VT, typename... Args>
void bar(const CT<VT, Args...> &cont)
{
	for (const auto &it : cont)
		std::cout << it << '\n';
	std::cout << "----\n";
}

int main()
{
	std::vector<int> v = { 1,2,3,4 };
	std::cout << "vector:\n";
	foo(v);

	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	std::cout << "list:\n";
	foo(l);

	// set has 3 template parameters
	std::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	std::cout << "set:\n";
	bar(s);

	std::cin.get();
}
