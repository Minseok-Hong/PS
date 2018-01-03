#include <stdio.h>

char string[101][101];
void input();

int main()
{
	input();
}

void input()
{
	for(int i = 0 ; i < 100 ; i++)
	{
		gets(string[i]);
		puts(string[i]);
	}
}