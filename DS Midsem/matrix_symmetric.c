#include <stdio.h>

int main()
{
	int a[3][3] = {1,0,4,0,2,1,4,1,3};
	int b[3][3] = {1,2,3,2,1,3,3,3,1};
	int c[3][4];
	for(int i=0 ; i<3 ; i++)
	{
		for(int j=0 ; j<3 ; j++)
		{
			if( i>=j )
			{
				c[i][j] = a[i][j];
			}
			if( i <=j )
			{
				c[i][j+1] = b[i][j];
			}	
		}
	}

	for(int i=0 ; i<3 ; i++)
	{
		for(int j=0 ; j<4 ; j++)
			printf("%6d", c[i][j]);
		printf("\n");
	}

}

