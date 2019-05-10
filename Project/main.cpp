#include <iostream>

class Top
{
public:
	Top() {}
	Top(int t) : top(t) {}
	virtual ~Top() {}
	int top = 1;
};

class Left : virtual public Top
{
public:
	Left() {}
	Left(int t, int l) : Top(t), left(l) {}
	int left = 2;
};

class Right : virtual public Top
{
public:
	Right() {}
	Right(int t, int r) : Top(t), right(r) {}
	int right = 3;
};

class Bottom : public Left, public Right
{
public:
	Bottom() {}
	//Bottom(int t, int l, int r, int b) : Left(t, l), Right(t, r), bottom(b) {}
	Bottom(int t, int l, int r, int b) : Top(t), Left(t, l), Right(t, r), bottom(b) {}
	int bottom = 4;
};

int main()
{
	Bottom bottom(1000, 2, 3, 4);
	std::cout << bottom.Left::top << ' ' << bottom.Right::top << ' '
		<< bottom.left << ' ' << bottom.right << ' ' << bottom.bottom << '\n';

	// bottom.Left::top and bottom.Right::top aren't 1000
	// because Top() is called before Left(int, int) and Right(int, int)
	// from Bottom() => need to call Top(int) from Bottom()

	std::cin.get();
	return 0;
}
