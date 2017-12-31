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

		for(int k = 0; k < i; k++)
		{
			printf(" ");
		}

		for(j = 0 ; j < a ; j++ )
		{
			printf("*");
		}

		if(i == input-1 )
			break;


		if(i != input && j == a)
		{
			printf("\n");
		}
	}
}