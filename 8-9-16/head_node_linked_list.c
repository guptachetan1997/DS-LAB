#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct HeadNode
{
	struct node *start;
	int count;
};

typedef struct node Mynode;
typedef struct HeadNode Head;

Mynode *get_new_node()
{
	Mynode *p;
	p = (Mynode *)malloc(sizeof(Mynode));
	return p;
}

void insertData(Head *h, int x)
{
	Mynode *p,*q;
	p = get_new_node();
	p->data = x;
	if(h->start == NULL || (h->start!=NULL && h->start->data > x))
	{
		p->next = h->start;
		h->start = p;
	}
	else
	{
		q = h->start;
		while(q->next!=NULL && q->next->data < x)
			q = q->next;
		p->next = q->next;
		q->next = p;
	}
	h->count++;
}

int deleteData(Head *h, int x)
{
	Mynode *p = h->start;
	int flag=0;
	while(p!=NULL)
	{
		if(p->next->data == x)
		{
			flag=1;
			break;
		}
		p = p->next;
	}
	if(flag)
	{
		Mynode *q = p->next;
		p->next = q->next;
		free(q);
		h->count--;
	}
	return flag;
}

void displayData(Head h)
{
	Mynode *p = h.start;
	while(p!=NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	Head head;
	head.start = NULL;
	head.count = 0;
	insertData(&head, 1);
	insertData(&head, 2);
	insertData(&head, 3);
	insertData(&head, 4);
	displayData(head);
	deleteData(&head, 1);
	displayData(head);
}