#include <stdio.h>
#define MAX 100

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

void push(char stack[], int *top , char op)
{
	if(*top > MAX-1)
		return;
	stack[++(*top)] = op;
}

char pop(char stack[], int *top)
{
	if(*top == -1)
		return 0;
	char ri = stack[(*top)--];
	return ri;
}

void display(char stack[], int top)
{
	if(top == -1)
		return;
	for(int i=top ; i>=0 ; i--)
		printf("%c", stack[i]);
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

int precedence(char a)
{
	switch(a)
	{
		case '$':
			return 0;
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;

	}
}

void infix_to_postfix(char infix[])
{
	char stack[MAX];
	int top = -1;
	for(int i=0 ; infix[i]!= '\n' ; i++)
	{
		if(is_operand(infix[i]))
		{
			printf("%c", infix[i]);
		}
		else if(infix[i] == '(')
			push(stack, &top, '(');
		else if(infix[i] == ')')
		{
			char temp;
			while(stack[top] != '(')
			{
				temp = pop(stack, &top);
				printf("%c", temp);
			}
			pop(stack, &top);
		}
		else if(infix[i] == '$')
		{
			display(stack, top);
			break;
		}
		else
		{
			char temp;
			while(top!=-1 && precedence(stack[top]) >= precedence(infix[i]))
			{
				temp = pop(stack, &top);
				printf("%c", temp);
			}
			push(stack, &top, infix[i]);
		}
	}
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
	char abc[] = "(4+8)*(6-5)/((3-2)*(2+2))$";
	// postfix_evaluate(abc);
	infix_to_postfix(abc);

}
