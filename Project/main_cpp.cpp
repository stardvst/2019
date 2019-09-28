#include <iostream>
#include <stack>
#include <list>

template <typename T, typename Container = std::list<T>>
struct MySet
{
public:
	void push_back(const T &value)
	{
		c.push_back(value);
	}

	std::size_t size() const
	{
		return c.size();
	}

private:
	Container c;
};

template <typename T>
struct MyContainer
{
	using value_type = T;
	using reference = T;
	using const_reference = T;
	using size_type = int;

	int size() const { std::cout << __FUNCTION__ << '\n'; return 0; }
	void push_back(const T &/* value */) { std::cout << __FUNCTION__ << '\n'; }
};

int main()
{
	std::cout << "MySet<int>\n";

	MySet<int> set1;
	set1.push_back(3);
	set1.push_back(3);
	set1.push_back(3);

	std::cout << set1.size() << '\n';

	std::cout << "\nMySet<int, MyContainer<int>>\n";

	MySet<int, MyContainer<int>> set2;
	set2.push_back(3);
	set2.push_back(3);
	set2.push_back(3);

	std::cout << set2.size() << '\n';

	std::cin.get();
}
