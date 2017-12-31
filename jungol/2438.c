#include <stdio.h>

int main()
{
	int input;

	scanf("%d",&input);

	for(int i = 1; i < input+1 ; i++)
	{
		for(int j = 0 ; j < i ; j++ )
		{
			printf("*");
		}
		if(i != input)
		{
			printf("\n");
		}
	}
}