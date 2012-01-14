#include <stdio.h>
#include <string.h>

void substr(char b[], char a[], int lensa)
{
	int len_b = strlen(b);
	int len_a = strlen(a);
	int i, j, count;

	count = 0;
	i = 0;
	j = 0;
	while(i < len_b){
		if ((a[j++] == b[i++]) && (a[j] == '\0')){
			count++;
			j = 0;
		}

	}
	printf("%d\n", count);
}

int main(int argc, const char *argv[])
{
	char *str = "hehehelolololhlsowjeoiij";
	char *subst = "helo";
	int i, j, count = 0;

	if (subst[2] == '\0')
		printf("%s     %d\n", __func__, __LINE__);

	substr(str, subst, strlen(str));

	return 0;
}
