#include <iostream>

class Top
{
public:
	int top = 1;
};

class Left : public Top
{
public:
	int left = 2;
};

class Right : public Top
{
public:
	int right = 2;
};

class Bottom : public Left, public Right
{
public:
	int bottom = 3;
};

int main()
{
	auto left = new Left;
	Top *top = left;

	std::cout << "left->left: " << left->left << ", left->top: " << left->top << '\n';
	std::cout << "top->top: " << top->top << '\n';

	auto bottom = new Bottom;
	left = bottom;
	
	Right *right = bottom;

	std::cout << "left: " << left << ", right: " << right << '\n';

	// top = bottom; ambiguous

	Top *topL = static_cast<Left *>(bottom);
	Top *topR = static_cast<Right *>(bottom);

	std::cout << "top (left): " << topL << ", top (right): " << topR << '\n';

	std::cin.get();
	return 0;
}
