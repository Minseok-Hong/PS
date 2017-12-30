#include <stdio.h>

int fibonacci(int n);

int input[10000];
int count[10000][2] = {0};
int i ;

int main()
{
	int number;

	scanf("%d",&number);

	for(i = 0 ; i < number ; i++)
	{
		scanf("%d",&input[i]);
		fibonacci(input[i]);
	}

	for(int j = 0 ; j < number; j++)
	{
		//printf("\n\n");
		printf("%d %d\n",count[j][0],count[j][1]);
	}

}

int fibonacci(int n) {
    if (n==0) {
        //printf("0");
        count[i][0]++;
        return 0;
    } else if (n==1) {
        //printf("1");
        count[i][1]++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}