//Implement stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	node *next;
};

node *get_new_node()
{
	node *p;
	p = (node *)malloc(sizeof(node));
	return p;
}

void push(node **top, int x_val)
{
	node *p = get_new_node();
	p->x = x_val;
	p->next = *top;
	*top = p;
}

int pop(node **top)
{
	if(*top == NULL)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	node *p = *top;
	*top = (*top)->next;
	return p->x;
}

void display(node *top)
{
	node *p = top;
	while(p != NULL)
	{
		printf("%d -> ", p->x);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	node *top;
	top = NULL;
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	display(top);
	printf("After popping once\n");
	pop(&top);
	display(top);
}
