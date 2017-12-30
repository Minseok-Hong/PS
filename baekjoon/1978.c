#include<stdio.h>
void check(int input);
int count = 0;

int main()
{
	int testNumber;
	int input[100];
	
	scanf("%d", &testNumber);

	for (int i = 0; i < testNumber; i++)
	{
		scanf("%d", &input[i]);
		check(input[i]);
	}
	printf("%d", count);

}

void check(int input)
{
	int check=0;

	for (int i = 2; i < input; i++)
	{
		if (input % i == 0)
			break;
		else
			check++;
	}

	if (check == input - 2)
		count++;

}
