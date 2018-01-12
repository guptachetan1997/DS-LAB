//Implement quicksort
#include <stdio.h>
#define MAX 100

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int get_partion(int A[], int start , int end)
{
	int pivot = A[end];
	int i=start-1;
	for(int j=start ; j<end ; j++)
	{
		if(A[j] <= pivot)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[end], A[i+1]);
	return i+1;
}

void quicksort(int A[], int start, int end)
{
	if(start < end)
	{
		int partion = get_partion(A, start, end);
		quicksort(A, start, partion-1);
		quicksort(A, partion+1, end);
	}
}

int main()
{
	int a[] = {2,23,4,15,62,13,7,8};
	printf("Original array\n");
	for(int i=0 ; i<8 ; i++)
		printf("%6d", a[i]);
	printf("\n");
	quicksort(a, 0, 7);
	printf("Sorted array\n");
	for(int i=0 ; i<8 ; i++)
		printf("%6d", a[i]);
	printf("\n");
}
