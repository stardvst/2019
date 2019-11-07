#include <iostream>

template <typename T>
T adder(T v)
{
	return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args)
{
	return first + adder(args...);
}

struct A{};

int main()
{
	long sum = adder(1, 2, 3, 8, 7);
	std::cout << "sum: " << sum << '\n';

	std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
	std::cout << "sum: " << adder(s1, s2, s3, s4) << '\n';

	//std::cout << "sum: " << adder(5, s2, s3, s4) << '\n';

	/*A a, b;
	A aSum = adder(a, b);*/

	std::cin.get();
}
