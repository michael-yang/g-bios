#include <stdio.h>

struct test{
	int a;
	int b;
	int c[0];
};

struct test1{
	struct test t;
	int a;
	int d;
};

int main()
{
	struct test1 t1;
	*(t1.t.c - 1) = 4;
	printf("                      %d\n", t1.t.b);

	return 0;
}
