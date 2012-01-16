#include <stdio.h>

void shell(int a[], int len)
{
	int i, j, gap;
	int tmp;
	for(gap = len / 2 ; gap > 0; gap /= 2)
	{
		for(i = gap; i < len; i++)
		{
			tmp = a[i];
			for(j = i - gap; j >= 0 && a[j] > tmp; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = tmp;
		}
	}
}

int main()
{
	int a[] = {4, 3, 2, 6, 8, 1, 0};
	int i;

	shell(a, 7);
	for(i = 0; i < 7; i++)
	{
		printf("%d  ", a[i]);
	}

	return 0;
}
