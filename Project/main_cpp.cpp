#include <iostream>

class A { int a; };
class B { int b; };
class C : public A, public B {};

int main()
{
	C c;
	A *a = &c;
	B *b = &c;

	std::cout << (a == reinterpret_cast<A *>(b)) << '\n';
	std::cout << (&c == a) << '\n';
	std::cout << (&c == b) << '\n';
	std::cout << (a == &c) << '\n';
	std::cout << (b == &c) << '\n';
	std::cout << a << ' ' << &c << '\n';
	std::cout << b << ' ' << &c << '\n';

	//std::cout << Bar::f() << '\n';

	std::cin.get();
}
