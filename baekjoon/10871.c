#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int number;
	int input[10001];
	int target;

	scanf("%d", &number);
	scanf("%d", &target);

	for (int i = 0; i < number; i++)
	{
		scanf("%d", &input[i]);
	}

	//printf("%d\n\n", target);
	for (int i = 0; i < number; i++)
	{
		//printf("if (target > input[i])\n\n");
		//printf("if (  %d   >    %d)\n\n", target, input[i]);
		if(target > input[i])
		{
			printf("%d ", input[i]);
		}
	}
}
