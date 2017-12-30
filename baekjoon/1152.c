#include <stdio.h>
#include <string.h>

int main()
{
	char string[1000001];
	int count = 0;
	int flag = 0;
	int length;

	gets(string);

	length = strlen(string);

	//printf("length == %d\n",length);

	for(int i = 0; i < length; i++)
	{
		if(((string[i] >= 65 && string[i] <=90) || (string[i] >=97 && string[i] <= 122)) && flag==0)
		{
			count++;
			flag++;
		}
		else if(string[i] == 32)
		{
			flag=0;
		}
	}
	printf("%d",count);
}