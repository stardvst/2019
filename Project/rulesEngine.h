#pragma once

#include <deque>
#include <algorithm>

class RulesEngine
{
public:
	void If(bool sufficientCondition)
	{
		sufficientConditions.push_back(sufficientCondition);
	}

	void NotIf(bool preventingCondition)
	{
		preventingConditions.push_back(preventingCondition);
	}

	/*bool operator()() const
	{
		const auto isTrue = [](bool b) { return b; };
		return std::any_of(sufficientConditions, isTrue) && std::none_of(preventingConditions, isTrue);
	}*/

	bool operator()() const
	{
		auto isTrue = [](bool b) { return b; };
		return std::any_of(std::begin(sufficientConditions), std::end(sufficientConditions), isTrue)
			&& std::none_of(std::begin(preventingConditions), std::end(preventingConditions), isTrue);
	}

private:
	std::deque<bool> sufficientConditions;
	std::deque<bool> preventingConditions;
};
