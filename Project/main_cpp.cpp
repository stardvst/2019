#include <iostream>

struct ABC
{

	void set(const int data)
	{
		std::cout << "set(" << data << ")\n";
		if (!this)
		{
			std::cout << "this is null, can't set\n";
			print(); // will crash, calls this->print()
			return;
		}
		this->data = data;
	}

	void get() const
	{
		if (!this)
		{
			std::cout << "null ptr deref, can't get\n";
			print(); // will crash, calls this->print()
			return;
		}

		print();
	}

	void print() const
	{
		//std::cout << "data = " << data << "\n";
		std::cout << "print\n"; // works isnce no access to data member
	}

	virtual void vprint()
	{
		std::cout << "virtual print\n"; // doesn't work since tries to deref vtable
	}

	int data;
};

int main()
{

	ABC abc;
	abc.set(100);
	abc.get();

	ABC *p1Abc = &abc;
	ABC *p2Abc = nullptr;

	p1Abc->set(111);
	p1Abc->get();

	p2Abc->set(222);
	p2Abc->get();
	// using fptr = void (ABC::*)();
	// fptr f = &ABC::vprint;
	// (p2Abc->*f)();
	// //p2Abc->vprint();

	std::cin.get();
}
