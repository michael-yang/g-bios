#include <stdio.h>

int recurse(int i)
{
	if (i == 1) {
		return 1;
	}

	return i * recurse(i - 1);
}

int main(int argc, const char *argv[])
{
	printf("%d\n", recurse(4));
	return 0;
}
