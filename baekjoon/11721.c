#include<stdio.h>

int main()
{
	char string[100];

	gets(string);

	for (int i = 0; i < 100; i++)
	{
		if (i % 10 == 0 && i != 0)
		{

			printf("\n");

		}
		if (string[i] == '\0')
			break;

		printf("%c", string[i]);

	}
	return 0;
}