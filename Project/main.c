#include <conio.h>

void *malloc(size_t);

void f(int n)
{
	int *p = malloc(n * sizeof(char));
	char c;
	void *pv = &c;
	int *pi = pv; // void* -> int*, not C++
}

int main()
{
	(void)_getch();
}