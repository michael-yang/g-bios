#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 128
char *diy_itoa(int n, char buf[]);

int main(int argc, char *argv[])
{
	char buf[LEN];
	memset(buf, 0, LEN);
	char *p;
	int i;
	int len = strlen(argv[1]);
	int  n = atoi(argv[1]);
	//p = (char *)malloc(30);

	p = diy_itoa(n, buf);
	if (argc < 2)
	{
		return -1;
	}
	printf("string after converting: ");
	for (i = len; p[i] != '\0'; i--)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	return 0;
}

char *diy_itoa(int n, char buf[])
{
	int i = 1;
	buf[0] = '\0';

	while (0 < n) {
		buf[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	//i--;

	return buf;
}
