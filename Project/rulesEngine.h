#pragma once

#include <deque>
#include <algorithm>

class RulesEngine;

class PreventingRulesEngine
{
public:
	explicit PreventingRulesEngine(RulesEngine &rulesEngine)
		: m_rulesEngine(rulesEngine)
	{
	}

	void If(bool preventingCondition);

private:
	RulesEngine &m_rulesEngine;
};

class RulesEngine
{
public:
	RulesEngine() : Not(*this)
	{
	}

	PreventingRulesEngine Not;

	void If(bool sufficientCondition)
	{
		suffConditions.push_back(sufficientCondition);
	}

	void NotIf(bool preventingCondition)
	{
		preventConditions.push_back(preventingCondition);
	}

	/*bool operator()() const
	{
		const auto isTrue = [](bool b) { return b; };
		return std::any_of(sufficientConditions, isTrue) && std::none_of(preventingConditions, isTrue);
	}*/

	bool operator()() const
	{
		auto isTrue = [](bool b)
		{
			return b;
		};
		return
			std::any_of(
				std::begin(suffConditions), std::end(suffConditions), isTrue) &&
			std::none_of(
				std::begin(preventConditions), std::end(preventConditions), isTrue);
	}

private:
	std::deque<bool> suffConditions;
	std::deque<bool> preventConditions;
};

inline void PreventingRulesEngine::If(bool preventingCondition)
{
	m_rulesEngine.NotIf(preventingCondition);
}
