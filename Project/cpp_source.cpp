#include <iostream>
#include <vector>
#include <unordered_map>

struct Person;
struct Animal;
struct Cat;
struct Dog;
class ReactionVisitor;

struct AnimalVisitor
{
	virtual void visitAnimal(Cat *animal) = 0;
	virtual void visitAnimal(Dog *animal) = 0;
};

struct Animal
{
	virtual std::string noise() const = 0;
	virtual void visit(ReactionVisitor &visitor) = 0;
	virtual ~Animal() = default;
};

struct Cat : Animal
{
	virtual std::string noise() const override
	{
		return "meow";
	}

	void visit(ReactionVisitor &visitor);
};

struct Dog : Animal
{
	virtual std::string noise() const override
	{
		return "woof";
	}

	void visit(ReactionVisitor &visitor) override;

	enum Breed { Dashchund, Labrador };
	Breed m_breed = Dashchund;
};

struct ReactionVisitor : AnimalVisitor
{
	ReactionVisitor(Person *person) : m_person(person) {}

	void visitAnimal(Cat *cat) override;
	void visitAnimal(Dog *dog) override;

	Person *m_person;
};

struct Person
{
	friend ReactionVisitor;

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

void Cat::visit(ReactionVisitor &visitor)
{
	visitor.visitAnimal(this);
}

void Dog::visit(ReactionVisitor &visitor)
{
	visitor.visitAnimal(this);
}

void ReactionVisitor::visitAnimal(Cat *cat)
{
	m_person->pet(cat);
}

void ReactionVisitor::visitAnimal(Dog *dog)
{
	if (dog->m_breed == Dog::Dashchund)
		m_person->runaway(dog);
	else
		m_person->pet(dog);
}

int main()
{
	auto dog = new Dog;
	auto cat = new Cat;

	Person p;
	p.ReactTo(dog);
	p.ReactTo(cat);

	std::cin.get();
	return 0;
}
