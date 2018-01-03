#include <stdio.h>


int main()
{
	/*
	char string[100][100];

	for (int i = 0; i < 100; i++)
	{
		gets_s(string[i], 100);
	}
	for (int i = 0; i < 100; i++)
	{
		printf("%s", string[i]);
	}
	*/

	char string[101];

	string[0] = '\0';
	while (fgets(string, 100, stdin))
	{
		printf("%s", string);
	}
	return 0;
}