#include <stdio.h>

int main()
{
	int number[4];
	int min = 10001;

	scanf("%d %d %d %d",&number[0],&number[1],&number[2],&number[3]);

	number[2] = number[2] - number[0];
	number[3] = number[3] - number[1];
	
	for(int i = 0 ; i < 4 ; i++)
	{
		if(min > number[i])
			min = number[i];
	}

	printf("%d",min);



}