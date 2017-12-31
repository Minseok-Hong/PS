#include <stdio.h>

int number;
int input[10001];
int sum=0;
int money;
int average[10001];

void sorting_1();
void sorting_2();
void scan();
void print();

int main()
{

	scan();
	//printf("%d\n\n",input[number-1]);
	sorting_1();

	if(sum <= money){
		//printf("if\n");
		printf("%d\n\n",input[number-1]);
	}
	else{
		//printf("else\n");
		for(int i = 0 ; i < number ; i++)
		{
			for(int j = 0 ; j < i ; j++)
			{
				average[i]  -= input[j];
			} 
			average[i] = ((money + average[i])/(number-i)) ;
		}
		sorting_2();
		printf("%d",average[number-1]);

	}
	
	//print();

}

void scan()
{
	scanf("%d",&number);

	for(int i = 0 ; i < number ; i++){
		scanf("%d",&input[i]);
		sum += input[i];

	}
	scanf("%d",&money);

}

void sorting_1()
{
	int temp;

	for (int i = 1; i < number; i++) { 
		for (int j = 0; j < number-i; j++) { 
   			if (input[j] > input[j+1]) { 
    			temp = input[j]; 
   				input[j] = input[j+1];
    			input[j+1] = temp;
   			}
 		}
 	}
}
void sorting_2()
{
	int temp;

	for (int i = 1; i < number; i++) { 
		for (int j = 0; j < number-i; j++) { 
   			if (average[j] > average[j+1]) { 
    			temp = average[j]; 
   				average[j] = average[j+1];
    			average[j+1] = temp;
   			}
 		}
 	}
}

/*
void print()
{

		for(int i = 0 ; i < number ; i++)
	{
		printf("%d ",input[i]);
		//printf("\n average == %d ",average[i]);

	}
	printf("\nsum == %d\n\n",sum);
	printf("max == %d",average[number-1]);
}
*/