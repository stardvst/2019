#include <map>
#include <iostream>
#include "shape.h"
#include "command.h"


int main()
{
	std::map<char, command *> commands;
	commands['c'] = new c();
	commands['p'] = new p();
	commands['m'] = new m();
	commands['d'] = new d();
	commands['u'] = new u();
	commands['r'] = new r();


	char c;
	std::cout << "Enter a command (c, p, m, d, u, r, e): ";
	std::cin >> c;

	while ('e' != c)
	{

		for (size_t i = 0; i < commands.size(); ++i)
		{
			if (commands.find(c) != commands.end())
			{
				commands[c]->execute();
				break;
			}
		}
		std::cout << "\nEnter a command (c, p, m, d, u, r, e): ";
		std::cin >> c;
	}

	for (std::map<char, command *>::iterator it = commands.begin(); it != commands.end(); ++it)
	{
		delete it->second;
	}

	commands.clear();

	return 0;
}