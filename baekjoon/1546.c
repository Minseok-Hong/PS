#include <stdio.h>

int main()
{
	int amount;
	float score[1001];
	float max=0;
	float sum=0;
	//int average;

	scanf("%d",&amount);

	for(int i = 0 ; i < amount ; i++)
	{
		if(i == 0){
			max= score[0];
		}

		scanf("%f",&score[i]);

		sum += score[i];

		if(score[i] > max)
			max = score[i];
	}

	//printf("max == %f\n",max);
	//printf("sum ==%f\n",sum);
	printf("%.2f\n", ((sum)*100)/(amount * max) );
	//printf("%d\n",);
	//printf("%d\n",);


}