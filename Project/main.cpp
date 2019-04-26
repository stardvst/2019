#include <cmath>
#include <iostream>

void f(double x, double y)
{
	double cos_x = std::cos(x);
	double cos_y = std::cos(y);
	if (cos_x != cos_y)
		std::cout << "surprise!"; // might end up here
}

int main()
{
	f(1.0, 1.0);

	float a = 1000.43;
	float b = 1000;
	std::cout << "a - b = " << a - b;
}
