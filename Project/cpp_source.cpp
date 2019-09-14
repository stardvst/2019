#include <iostream>
#include <boost/intrusive_ptr.hpp>

struct Person
{
	std::string name = "Empty name";
	int age;

	// intrusive ptr
	long references = 0;
};

// must provide these functions
inline void intrusive_ptr_add_ref(Person *person)
{
	++person->references;
}

inline void intrusive_ptr_release(Person *person)
{
	if (--person->references == 0)
		delete person;
}

void test()
{
	//std::shared_ptr<Person> person(new Person);

	auto pPerson = new Person;

	// same object can be "shared", unlike shared_ptr
	boost::intrusive_ptr<Person> person1(pPerson);
	boost::intrusive_ptr<Person> person2(pPerson);
	std::cout << person1->name << '\n';
	std::cout << person2->name << '\n';
}

int main()
{
	test();

	std::cin.get();
	return 0;
}
