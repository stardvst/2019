#pragma once

#include <vector>
#include <string>

class Individual
{
public:
	explicit Individual(std::string chromosome);

	Individual mate(const Individual &parent2);

	int calcFitness();

	std::string chromosome;
	int fitness;
};
