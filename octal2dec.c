#include <stdio.h>
#include <stdlib.h>

//fixme! to add a function here and handle exception
int oct2dec(int n)
{
	int n = 232;
	int sum = 0;
	int i;

	for (i = 1; n > 0; i *= 8) {
		if (n % 10 > 7 || n % 10 < 0) {
			printf("%s\n", "Is it octal number ? \npls input the right number !");

			//fixme to return ?
			break;
		}
		sum += (n % 10) * i;
		n = n / 10;
	}
}
int main(int argc, const char *argv[])
{

	printf("%d\n", (int)sum);

	return 0;
}
