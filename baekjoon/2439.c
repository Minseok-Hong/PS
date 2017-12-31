#include <stdio.h>

int main()
{
	int input;
	int i,j,k;
	int a;

	scanf("%d",&input);

	for(int i = 0 ; i < input ; i++)
	{
		a = input-i;

		for(j = 0 ; j < a-1 ; j++ )
		{
			printf(" ");
		}

		for(int k = 0; k < i+1; k++)
		{
			printf("*");
		}

		if(i != input)
		{
			printf("\n");
		}
	}
}