#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

struct cmp
{
	bool operator()(int i, const std::pair<int, double> &p) const
	{
		return i < p.first;
	}

	bool operator()(const std::pair<int, double> &p, int i) const
	{
		return p.first < i;
	}
};

int main()
{
	std::set<int> s1{ 1, 2, 3, 4 };
	std::map<int, double> s2{ {1, 0}, {2,0}, {4,0} };

	std::set<int> result;

	std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
		std::inserter(result, result.end()), cmp());

	std::cout << *result.begin(); // will print 3

	std::cin.get();
}
