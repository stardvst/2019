#include <iostream>
#include <fstream>
#include <iterator>

int main()
{
	std::ifstream ifstr("2048.h");
	std::string content((std::istreambuf_iterator<char>(ifstr)),
		std::istreambuf_iterator<char>());
	std::cout << content << '\n';

	std::cin.get();
}