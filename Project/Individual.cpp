#include "Individual.h"
#include <utility>
#include "functions_cpp.h"

Individual::Individual(std::string chromosome)
	: chromosome(std::move(chromosome))
{
	fitness = calcFitness();
}

Individual Individual::mate(const Individual &parent2)
{
	std::string childChromosome;

	const auto len = static_cast<int>(chromosome.size());
	for (auto i = 0; i < len; ++i)
	{
		const float p = randomNum(0, 100) / 100;
		if (p < 0.45)
			childChromosome += chromosome[i];
		else if (p < 0.9)
			childChromosome += parent2.chromosome[i];
		else
			childChromosome += mutatedGene();
	}

	return Individual(childChromosome);
}

int Individual::calcFitness()
{
	const auto len = static_cast<int>(target.size());
	auto fitness = 0;
	for (auto i = 0; i < len; ++i)
	{
		if (chromosome[i] != target[i])
			++fitness;
	}
	return fitness;
}
