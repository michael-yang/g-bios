#include <stdio.h>
#include <stdlib.h>

typedef struct list List;

struct list
{
	int data;
	struct list *next;
};

struct list *create(int n)
{
	int i;
	struct list *list, *first = NULL;

	for(i = 0; i < n; i++)
	{
		list = (struct list *)malloc(sizeof(*first));
		list->data = i;
		list->next = first;
		first = list;
	}

	return first;
}

#if 1
List *list_create(struct list *first, int n)
{
	int i;
	struct list *q, *p = first;

	for(i = 1; i < n; i++)
	{
		q = (struct list *)malloc(sizeof(*q));
		q->data = i;
		q->next = NULL;

		if (i == 1) {
			p = q;
		}
		else {
			p->next = q;
			p = p->next;
		}
	}
	if (first == NULL)
	{
		printf("first is NULL\n");
	}

	return first;
}
#endif

List *reverse(List *p)
{
	List * ret;

	if (p == NULL || p->next == NULL){
		return p;
	}

	ret = reverse(p->next);

	p->next->next = p;
	p->next = NULL;

	return ret;
}

void traverse(struct list *first)
{
	while (first)
	{
		printf("%d\n", first->data);
		first = first->next;
	}
}

void destroy(struct list *first)
{
	struct list *p;

	while (first)
	{
		p = first->next;
		free(first);
		first = p;
	}
}

int main()
{
	struct list *first;
	first = list_create(first, 5);
	first = reverse(first);
	traverse(first);

	return 0;
}
