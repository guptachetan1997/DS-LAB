#include <stdio.h>
#define MAX 10

float value_of_var(char var)
{
	switch(var)
	{
		case 'a':
			return 1;
		case 'b':
			return 2;
		case 'c':
			return 3;
		case 'd':
			return 4;
		case 'e':
			return 5;
	}
}

void push(float stack[], int *top , float op)
{
	if(*top > MAX-1)
		return;
	stack[++(*top)] = op;
}

float pop(float stack[], int *top)
{
	if(*top == -1)
		return 0;
	float ri = stack[(*top)--];
	return ri;
}

void display(float stack[], int top)
{
	if(top == -1)
		return;
	for(int i=top ; i>=0 ; i--)
		printf("%f -> ", stack[i]);
	printf("\n");
}

int is_operand(char c)
{
	switch(c)
	{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
			return 1;

	}
	return 0;
}

void postfix_evaluate(char postfix[])
{
	float stack[MAX];
	int top = -1;
	//char *p = postfix;
	//printf("%s", p);
	for(int i=0 ; postfix[i]!='$'; i++)
	{
		if(is_operand(postfix[i]))
		{
			push(stack, &top, value_of_var(postfix[i]));
		}
		else
		{
			int operand2 = pop(stack, &top);
			int operand1 = pop(stack, &top);
			float res;
			switch(postfix[i])
			{
				case '+':
					res = operand1 + operand2;
					break;
				case '-':
					res = operand1 - operand2;
					break;
				case '*':
					res = operand1 * (operand2*1.0);
					break;
				case '/':
					res = operand1 / (operand2*1.0);
					break;
			}
			push(stack, &top, res);
		}
	}
	printf("%s evalutes to %f", postfix, pop(stack, &top));
}

int main()
{
	// float stack[MAX];
	// int top = -1;
	// push(stack, &top, value_of_var('a'));
	// push(stack, &top, value_of_var('b'));
	// push(stack, &top, value_of_var('c'));
	// display(stack, top);
	// pop(stack, &top);
	// display(stack, top);
	char abc[] = "abcd*+/$";
	postfix_evaluate(abc);

}
