//Implement mergesort
#include <stdio.h>
#define MAX 100

void merge(int A[], int start, int mid, int end)
{
	int temp[MAX];
	for(int i=start ; i<=end ; i++)
	{
		temp[i] = A[i];
	}
	int k=start,i,j;
	for(i=start,j=mid+1 ; i<=mid && j<=end ; )
	{
		if(temp[i] <= temp[j])
		{
			A[k++] = temp[i++]; 
		}
		else
		{
			A[k++] = temp[j++];
		}
	}
	while(i <= mid)
		A[k++] = temp[i++];
	while(j <= end)
		A[k++] = temp[j++];
}

void mergesort(int A[], int start, int end)
{
	if(start < end)
	{
		int mid = (start+end)/2;;
		mergesort(A, start, mid);
		mergesort(A, mid+1, end);
		merge(A, start, mid, end);
	}
}

int main()
{
	int a[] = {2,23,4,15,62,13,7,8};
	printf("Original array\n");
	for(int i=0 ; i<8 ; i++)
		printf("%6d", a[i]);
	printf("\n");
	mergesort(a, 0, 7);
	printf("Sorted array\n");
	for(int i=0 ; i<8 ; i++)
		printf("%6d", a[i]);
	printf("\n");
}
