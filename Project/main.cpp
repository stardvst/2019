#include <iostream>

void f(int n)
{
	int *p = new int(n * sizeof(char));
	char c;
	void *pv = &c;
	int *pi = pv; // void* -> int*, not C++
}

int main()
{
	std::cin.get();
}