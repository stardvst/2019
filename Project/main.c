#include <stdio.h>
#include <conio.h>

int main()
{
	char ch1 = 0;
	char ch2 = 0;
	char *p1 = &ch1;
	void *p2 = p1;

	int *p3 = p2; // unsafe, legal C, not C++

	printf("%d %d\n", ch1, ch2);
	*p3 -= 1;
	printf("%d %d\n", ch1, ch2);

	(void)_getch();
}