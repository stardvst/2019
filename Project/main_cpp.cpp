#include <iostream>

struct A
{
	A(int &p) : a(p) {}
	void operator()() const { ++a; }
	int &a;
};

int main()
{
	int p = 5;
	A o(p);
	std::cout << o.a << '\n';
	o();
	std::cout << o.a << '\n';

	std::cin.get();
}
