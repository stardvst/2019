#include <iostream>
#include "rulesEngine.h"

int main()
{
	int a, b, c;
	std::cout << "a: ";
	std::cin >> a;

	std::cout << "b: ";
	std::cin >> b;

	std::cout << "c: ";
	std::cin >> c;

	RulesEngine rules;

	rules.If(a > 0);
	rules.If(b > 0);
	rules.NotIf(c == 0);
	std::cin.ignore();

	std::cout << "rules satisfied: " << rules() << '\n';

	std::cin.get();
}
