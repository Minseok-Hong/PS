#include<stdio.h>

int main()
{
	int input;

	scanf("%d",&input);

	for (int i = 0; i < input; i++)
	{
		printf("%d\n", i + 1);
	}
}