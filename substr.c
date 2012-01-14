#include <stdio.h>
#include <string.h>

void test(char *p, char *q)
{
	int count = 0;
	printf("%s\n", p);
	while(*p != '\0')
	{
		if (0 == strncmp(p, q, strlen(q))) {
			printf("%d\n", strlen(p));
			count++;
		}
			p++;
	}
	printf("%d\n", count);
}

int main(int argc, const char *argv[])
{
	char *p = "sjlsjfkjsjjjksljkkjsj";
	char *q = "sj";

	test(p, q);
	return 0;
}
