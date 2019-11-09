#include <iostream>
struct Base
{
	virtual void f() { std::cout << "Base::f()" << std::endl; }
};

struct Derived :Base
{
	virtual void f() { std::cout << "Derived::f()" << std::endl; }
};


void SomeMethod(Base *object, void (Base:: *ptr)())
{
	(object->*ptr)();
}

// void SomeMethod(Base &object, void (Base::*ptr)())
// {
//     (object.*ptr)();
// }


int main()
{
	Base b;
	Derived d;
	Base *p = &b;
	SomeMethod(p, &Base::f); //calls Base::f()
	p = &d;
	SomeMethod(p, &Base::f); //calls Derived::f()

	std::cin.get();
}
