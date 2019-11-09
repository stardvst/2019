#include "functions_cpp.h"

int randomNum(const int start, const int end)
{
	const auto range = (end - start) + 1;
	return start + (rand() % range);
}

char mutatedGene()
{
	const auto randIdx = randomNum(0, static_cast<int>(genes.size()) - 1);
	return genes[randIdx];
}

std::string createGnome()
{
	const auto len = static_cast<int>(target.size());

	std::string gnome;
	for (auto i = 0; i < len; ++i)
		gnome += mutatedGene();
	return gnome;
}
