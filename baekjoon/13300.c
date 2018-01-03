#include <stdio.h>

int main()
{
	int num, max;
	int grade, sex;
	int roomNum=0;
	int room[3][7]={0};

	scanf("%d %d",&num,&max);

	for(int i = 0 ; i < num; i++)
	{
		scanf("%d %d",&sex,&grade);

		room[sex][grade] = room[sex][grade]+1;
		//printf("sex == %d  grade == %d room[sex][grade]==%d \n",sex,grade,room[sex][grade]);

	}

	for(int i = 0; i < 2; i++)
	{
		for(int j = 1 ; j < 7 ; j++)
		{
			if(room[i][j] >max)
			{
				roomNum += (room[i][j]/max);
				//printf("!!!!!!!!!!!!!!!!!!\n");
				if(room[i][j]%max >0)
				{
					roomNum++;
					//printf("@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
				}
			}
			else if (room[i][j] > 0)
			{
				roomNum++;
				//printf("##################\n");
			}
		}
		
	}
	printf("%d",roomNum);

}