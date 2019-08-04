#include <iostream>
#include <vector>

enum AnimalType
{
	DOG, CAT, PIG, LIZARD, HORSE
};

struct Animal
{
	virtual std::string noise() const = 0;
	virtual AnimalType getType() const = 0;
	virtual ~Animal() = default;
};

using AnimalCollection = std::vector<Animal *>;

struct Cat : Animal
{
	virtual std::string noise() const override
	{
		return "meow";
	}

	virtual AnimalType getType() const override
	{
		return CAT;
	}
};

struct Dog : Animal
{
	virtual std::string noise() const override
	{
		return "woof";
	}

	virtual AnimalType getType() const override
	{
		return DOG;
	}
};

struct Horse : Animal
{
	virtual std::string noise() const override
	{
		return "weef";
	}

	virtual AnimalType getType() const override
	{
		return HORSE;
	}
};

struct Person
{
	void ReactTo(Animal *animal)
	{
		if (animal->getType() == CAT || animal->getType() == HORSE)
			pet(animal);
		else if (animal->getType() == DOG)
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
