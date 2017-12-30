#include <stdio.h>

int main()
{
	int number;
	int arrayA[51], arrayB[51];
	int tmp;
	int sum=0;
/////////////////////////////////////////////////////////
	scanf("%d",&number);

	for(int i = 0 ; i < number; i++)
	{
		scanf("%d",&arrayA[i]);
	}

	for(int i = 0 ; i < number; i++)
	{
		scanf("%d",&arrayB[i]);		
	}
/////////////////////////////////////////////////////////
	for(int i = 0 ; i < number; i++)
	{
		for(int j = i+1 ; j < number; j++)
		{
			if(arrayA[i]>arrayA[j]){
				tmp = arrayA[i];
				arrayA[i] = arrayA[j];
				arrayA[j] = tmp;
			}
			
			if(arrayB[i]>arrayB[j]){
				tmp = arrayB[i];
				arrayB[i] = arrayB[j];
				arrayB[j] = tmp;
			}
		}
	}
	/*
	//printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	for(int i = 0 ; i < number; i++){
		printf("%d",arrayA[i]);
	}
	printf("\n");
	
	for(int i = 0 ; i <number; i++){
		printf("%d",arrayB[i]);
	}
	printf("\n");	
	*/

	for(int i = 0 ; i < number;i++)
	{
		sum += arrayA[i] * arrayB[number-i-1];
	}
	printf("%d", sum);
}