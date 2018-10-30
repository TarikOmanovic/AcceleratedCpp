#include <iostream>

int
next(
	int n)
{
	return n + 1;
}

int
main()
{
	int (*fp)(int);

	fp = next;
	fp = &next;

	return 0;
}