#include <stdio.h>

int main()
{
	int monthAmount[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char String[7][10] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int month;
	int day;
	int amount=0;
	
	scanf("%d %d",&month,&day);

	for(int i = 0 ; i < month-1; i++)
	{
		amount = amount + monthAmount[i];
	}
	amount += day;

	//printf("%d",amount);

	printf("%s",String[amount%7]);

}