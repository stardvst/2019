#include <iostream>
#include <vector>
#include <unordered_map>

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

struct Person;
using ReactionHash = std::unordered_map<AnimalType, void (Person:: *)(Animal *)>;

struct Person
{
	ReactionHash getMap() const
	{
		ReactionHash hash;
		hash[CAT] = &Person::pet;
		hash[DOG] = &Person::runaway;
		hash[HORSE] = &Person::pet;
		return hash;
	}

	void ReactTo(Animal *animal)
	{
		auto functions = getMap();
		(this->*functions[animal->getType()])(animal);
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
