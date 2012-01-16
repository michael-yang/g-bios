#include <stdio.h>

int global[10] = {1};

void test(int a[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		a[i] = i;
	}
	printf("sizeof a in test = %d\n", sizeof(a));
}

int main(int argc, const char *argv[]) {
	int b[10];
	int i;
	for (i = 0; i < 10; i++) {
		b[i] = i;
	}
	test(b, 10);
	global[1] = 8;
	printf("%d\n", global[1]);
	printf("sizeof b = %d\n", sizeof(b));
	printf("sizeof global = %d\n", sizeof(global));

	return 0;
}
