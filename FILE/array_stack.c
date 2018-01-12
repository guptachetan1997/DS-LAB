//Implement a stack using an array.
#include <stdio.h>
#define MAX 50
#define INF -100000

struct stack
{
	int array[50];
	int top;
	int size;
};

void push(struct stack &s)
{
	if(s.top != s.size)
	{
		int temp;
		printf("Enter the input : ");
		scanf("%d", &temp);
		s.array[++s.top] = temp;
	}
	else
	{
		printf("Stack Overflow\n");
	}
}

int pop(struct stack &s)
{
	if(s.top != -1)
	{
		int temp = s.array[s.top--];
		return temp;
	}
	else
	{
		printf("Stack Underflow\n");
		return INF;
	}
}

void display(struct stack &s)
{
	if(s.top != -1)
	{
		for(int i=s.top ; i>=0 ; i--)
		{
			printf("%d->", s.array[i]);
		}
		printf("\n");
	}
}

int main()
{
	struct stack s;
	s.top = -1;
	s.size = MAX;
	push(s);
	push(s);
	push(s);
	push(s);
	display(s);
	printf("After removing 1 element from stack\n");
	int c = pop(s);
	display(s);
}
