#include <stdio.h>

char *my_itoa(int n, char buf[])
{
	int i = 1;
	buf[0] = '\0';

	while(0 <  n)
	{
		buf[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}

	return buf;
}

int main(int argc, const char *argv[])
{
	char buf[40];

	memset(buf, 0, 40);
	buf = my_itoa(234, buf);
	for (i = 0; i < count; i++) {
		/* code */
	}

	return 0;
}
