#include <stdio.h>
#include <stdlib.h>

struct list
{
	int data;
	struct list *next;
};

void create(struct list *first, int n)
{
	int i;
	struct list *list = first;
	for(i = 0; i < n; i++)
	{
		first = (struct list *)malloc(sizeof(*first));
		first->data = i;
		first->next = NULL;
	}
	list
}

void traverse(struct list *first)
{
	while (first)
	{
		printf("%d\n", first->data);
		first = first->next;
	}
}

int main()
{
	struct list *l;
	create(l, 5);
	traverse(l);

	return 0;
}
