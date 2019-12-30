#include <iostream>

namespace [[deprecated]] old_stuff
{

void legecy()
{
}

}

int main()
{
	old_stuff::legecy();

	std::cin.get();
}