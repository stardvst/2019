#include <iostream>

class A
{
public:
	virtual void f(int a = 4) { std::cout << a; }
};

class B : public A
{
public:
	virtual void f(int a = 6) { std::cout << a; }
};

int main()
{
	B *b = new B;
	b->f();
}