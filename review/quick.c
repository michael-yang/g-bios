#include <stdio.h>

#define SWAP(x, y)  do {x = x + y; y = x - y; x = x - y;} while(0)

void quick(int a[], int len)
{
	int i = 0;
	int j = len - 1;
	int flag = 0;

	if (len == 0)
		return;


	while(i != j)
	{
		if(a[i] > a[j])
		{
			SWAP(a[i], a[j]);
			flag = 1 - flag;
		}
		flag == 1 ? i++ : j--;
	}

	quick(a, i);
	quick(a + i + 1, len - i - 1);
}

int main()
{
	int i;
	int a[] = {3, 5, 9, 2, 3, 34};
	quick(a, 6);
	for(i = 0; i < 6; i++)
	{
		printf("%d  ", a[i]);
	}

	return 0;
}
