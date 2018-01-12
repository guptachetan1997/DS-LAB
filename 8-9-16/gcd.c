#include <stdio.h>

int gcd(int a, int b)
{
	if(a > b)
		return gcd(a-b,a);
	else if(b > a)
		return gcd(b-a,a);
	else
		return a;
}

int main()
{
	printf("%d \n", gcd(12,13));
}