#include <stdlib.h>
#include <stdio.h>

struct node
{
	int x;
	struct node *next;
};

void insert(struct node **start, int val)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->x = val;
	p->next = NULL;
	if(*start == NULL)
	{
		*start = p;
	}
	else
	{
		struct node *q = *start;
		while(q->next!=NULL) q = q->next;
		q->next = p;
	}
}

void reverse(struct node **start)
{
	struct node *prev = NULL;
	struct node *current = *start;
	struct node *future;
	while(current!=NULL)
	{
		future = current->next;
		current->next = prev;
		prev = current;
		current = future;
	}
	*start = prev;
}

void display(struct node *start)
{
	struct node *p = start;
	while(p!=NULL)
	{
		printf("%d -> ", p->x);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	struct node *start = NULL;
	insert(&start, 17);
	insert(&start, 15);
	insert(&start, 20);
	insert(&start, 21);
	insert(&start, 8);
	insert(&start, 7);
	insert(&start, 2);
	display(start);
	reverse(&start);
	display(start);
}