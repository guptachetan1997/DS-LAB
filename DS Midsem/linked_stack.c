#include <stdio.h>
#include <stdlib.h>

struct LinkedStack
{
	int val;
	struct LinkedStack *link;
};

typedef struct LinkedStack stack;

stack *new_node()
{
	stack *p;
	p = (stack *)malloc(sizeof(stack));
	return p;
}

void push(stack **top, int value)
{
	stack *p;
	p = new_node();
	p->val = value;
	if(*top == NULL)
	{
		p->link = NULL;
		*top = p;
	}
	else
	{
		p->link = *top;
		*top = p;
	}
}

void pop(stack **top)
{
	if(*top == NULL)
	{
		printf("Stack Underflow \n");
		return;
	}
	printf("---------  %d --------\n", (*top)->val);
	stack *p = *top;
	*top = (*top)->link;
	free(p);
}

void display(stack *top)
{
	printf("------------------------\n");
	stack *p = top;
	while(p!=NULL)
	{
		printf("%d -> ", p->val);
		p = p->link;
	}
	printf("\n");
	printf("------------------------\n");
}

int main(int argc, char const *argv[])
{
	stack *top=NULL;
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	push(&top, 5);
	display(top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	pop(&top);
	display(top);
	pop(&top);
	push(&top, 55);
	display(top);
	pop(&top);
}