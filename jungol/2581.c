#include<stdio.h>

void check(int input);
int sumNumber = 0;
int count = 0;
int firstNumber;

int main()
{
	int minNumber;
	int maxNumber;

	scanf("%d", &minNumber);
	scanf("%d", &maxNumber);

	for (int i = minNumber; i <= maxNumber; i++)
	{
		check(i);
	}
	if (sumNumber == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n", sumNumber);
		printf("%d", firstNumber);
	}
	
}

void check(int input)
{
	int check = 0;

	for (int i = 2; i < input; i++)
	{
		if (input % i == 0)
			break;
		else
			check++;
	}

	if (check == input - 2)
	{
		sumNumber = sumNumber + input;
		while (count == 0)
		{
			firstNumber = input;
			count++;
		}
	}
}