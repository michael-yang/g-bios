#include <stdio.h>

void straight(int a[], int len)
{
	int i, j;
	int tmp;

	for (i = 1; i < len; i++)
	{
		tmp = a[i];
		for(j = i - 1; j >= 0 && a[j] > tmp; j--)
		{
				a[j + 1] = a[j];
		}
#if 0
		for(j = i - 1; j >= 0; j--)
		{
			if(a[j] > tmp){
				a[j + 1] = a[j];
			}
		}
#endif

		a[j + 1] = tmp;
	}
}

int main()
{
	int i;
	int a[] = {2, 5, 1, 4, 0, 8, 9};
	straight(a, 7);

	for(i = 0; i < 7; i++)
		printf("%d\n", a[i]);

	return 0;
}
