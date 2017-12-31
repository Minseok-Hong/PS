#include <stdio.h>

int main()
{
	int inputNumber;
	int remainder;
	int x_remainder;
	int y_remainder;
	int number;
	int max_x;
	int max_y;
	int min = -1;
	int i,j;
	int flag=0;

	scanf("%d",&inputNumber);

	for(i = 1 ; i < inputNumber; i++)
	{
		x_remainder = inputNumber % (5*i);

		if(x_remainder == inputNumber){
			max_x = (i-1);
			break;
		}
	}

	for(j = 1 ; j < inputNumber; j++)
	{
		y_remainder = inputNumber % (3*j);

		if(y_remainder == inputNumber){
			max_y = (j-1);
			break;
		}
	}

	//printf("x_remainder = %d\n",x_remainder);
	//printf("max_x = %d\n",max_x);

	for(int i = max_x ; i >= 0; i--)
	{
		//printf("i == %d\n\n",i);
		for(int j = max_y ; j >= 0 ; j--)
		{
			number = ((i)*5) + (j*3);

			//printf("number == %d\n\n",number);

			if(number == inputNumber)
			{
				min = (i+j);
				flag++;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	//printf("min == %d\n\n",min);
	printf("%d",min);
}








