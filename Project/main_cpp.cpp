#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <array>

template <
	template <typename, typename> class ContainerType,
	typename ValueType,
	typename AllocType
>
void printContainer(const ContainerType<ValueType, AllocType> &c)
{
	for (const auto &v : c)
		std::cout << v << ' ';
	std::cout << '\n';
}

template <
	template <typename, typename...> class ContainerType,
	typename ValueType,
	typename... Args
>
void printContainerVar(const ContainerType<ValueType, Args...> &c)
{
	for (const auto &v : c)
		std::cout << v << ' ';
	std::cout << '\n';
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p)
{
	out << '[' << p.first << ", " << p.second << ']';
	return out;
}

int main()
{
	std::vector<int> v{ 3, 5, 7, 1 };
	printContainer(v);

	std::list<int> l{ 3, 5, 7, 1 };
	printContainer(l);

	std::set<int> s{ 3, 5, 7, 1 };
	//printContainer(s);
	printContainerVar(s);

	std::map<int, std::string> m{ {42, "foo"}, {81, "bar"} };
	//printContainer(m);
	printContainerVar(m);

	std::string ss{ "abcd" };
	printContainerVar(ss);

	// doesn't work
	//std::array<int, 4> a{ 3, 5, 7, 1 };
	//printContainerVar(a);

	std::cin.get();
}
