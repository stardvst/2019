#include <iostream>

struct Player
{
	std::shared_ptr<Player> companion;
	~Player() { std::cout << __FUNCTION__ << '\n'; }
};

int main()
{
	std::shared_ptr<Player> jasmine(new Player);
	std::shared_ptr<Player> albert(new Player);
	jasmine->companion = albert;
	albert->companion = jasmine;

	// circular dependency: dtors are never called, oops!

	std::cin.get();
	return 0;
}