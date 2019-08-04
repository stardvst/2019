#include <iostream>
#include <vector>

struct Animal
{
	virtual std::string noise() const = 0;
	virtual ~Animal() = default;
};

using AnimalCollection = std::vector<Animal *>;

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
};

struct Horse : Animal
{
	virtual std::string noise() const override
	{
		return "weef";
	}
};

struct Person
{
	void ReactTo(Animal *animal)
	{
		if (dynamic_cast<Cat *>(animal) || dynamic_cast<Horse *>(animal))
			pet(animal);
		else if (dynamic_cast<Dog *>(animal))
			runaway(animal);
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

int main()
{
	auto cat = new Cat;
	auto dog = new Dog;
	auto horse = new Horse;

	Person p;
	p.ReactTo(cat);
	p.ReactTo(dog);
	p.ReactTo(horse);

	std::cin.get();
	return 0;
}
