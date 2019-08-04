#include <iostream>
#include <vector>
#include <unordered_map>

struct Person;
struct ReactionVisitor
{
	ReactionVisitor(Person *person) : m_person(person) {}
	Person *m_person;
};

struct Animal
{
	virtual std::string noise() const = 0;
	virtual void visit(ReactionVisitor &visitor) = 0;
	virtual ~Animal() = default;
};

struct Person
{
	void ReactTo(Animal *animal)
	{
		ReactionVisitor visitor(this);
		animal->visit(visitor);
	}

	void pet(Animal *a)
	{
		std::cout << "petting" << std::endl;
	}

	void runaway(Animal *a)
	{
		std::cout << "run away" << std::endl;
	}
};

struct Cat : Animal
{
	virtual std::string noise() const override
	{
		return "meow";
	}
};

struct Dog : Animal
{
	virtual std::string noise() const override
	{
		return "woof";
	}

	void visit(ReactionVisitor &visitor) override
	{
		// drawback: why should dog dictate how person reacts to it
		auto person = visitor.m_person;
		if (m_breed == Dashchund)
			person->runaway(this);
		else
			person->pet(this);
	}

	enum Breed { Dashchund, Labrador };
	Breed m_breed = Dashchund;
};

int main()
{
	auto dog = new Dog;

	Person p;
	p.ReactTo(dog);

	std::cin.get();
	return 0;
}
