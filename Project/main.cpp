#include <iostream>

class Top
{
public:
	int top = 1;
};

class Left : virtual public Top
{
public:
	int left = 2;
};

class Right : virtual public Top
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
	auto bottom = new Bottom;
	Left *left = bottom;
	Right *right = bottom;

	std::cout << "bottom: " << bottom << '\n';
	std::cout << "left: " << left << ", left->left: " << left->left << ", left->top: " << left->top << '\n';
	std::cout << "right: " << right << ", right->right: " << left->left << ", right->top: " << left->top << '\n';

	std::cin.get();
	return 0;
}
