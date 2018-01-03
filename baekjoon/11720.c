#include <stdio.h>
#include <stdlib.h>

int main()
{
	int input;
	char number[101];
	int amount=0;

	scanf("%d",&input);

	scanf("%s",number);

	for(int i = 0 ; i < input ; i++)
	{
		amount += (number[i]-48);
	}
	printf("%d",amount);
}