#include <iostream>

template <typename Derived>
struct Base
{
	void do_smth()
	{
		static_cast<Derived *>(this)->do_smth_impl();
	}

private:
	void do_smth_impl()
	{
		std::cout << "default impl\n";
	}
};

struct Foo : Base<Foo>
{
	void do_smth_impl()
	{
		std::cout << "foo impl\n";
	}
};

struct Bar : Base<Bar>
{
};

template <typename Derived>
void use(Base<Derived> &o)
{
	o.do_smth();
}

int main()
{
	Foo foo;
	Bar bar;

	use(foo);
	use(bar);

	//Base<int> d;
	//use(d);

	std::cin.get();
}
