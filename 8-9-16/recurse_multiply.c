#include <stdio.h>

int multiply(int a, int b)
{
	if (b == 0 || a == 0)
		return 0;
	else if(b == 1)
		return a;
	else
		return a+multiply(a,b-1);
}

int main()
{
	printf("%d \n", multiply(112,3));
}