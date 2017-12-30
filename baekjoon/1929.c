#include <stdio.h>
//#include <math.h>

void check(int input);

int main()
{
	int minNumber;
	int maxNumber;

	scanf("%d %d", &minNumber, &maxNumber);

	for (int i = minNumber; i <= maxNumber; i++){
		check(i);
	}

}

void check(int input)
{
	int check = 0;
	int i;
	for ( i = 2; i*i <= input; i++){////////////////////it is good that root expressed this route
		if (input % i == 0)
			break;
	}
	if(i*i > input && input != 1){
		printf("%d\n", input);
	}
}
