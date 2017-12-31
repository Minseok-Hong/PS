#include <stdio.h>
#define MAXSIZE 105

int comNum, edgeNum;
int map[MAXSIZE][MAXSIZE];
int check[MAXSIZE];
int queue[MAXSIZE*MAXSIZE];
int front = 0 , rear = 0 ;
int tmpX, tmpY;
int count=0;

int main()
{
	scanf("%d",&comNum);
	scanf("%d",&edgeNum);

	for(int i = 0 ; i <= comNum+1; i++){
		for(int j = 0 ; j <= comNum+1; j++){
			map[i][j] = 0;
			check[i] = 0 ;
		}
	}

	for(int i = 1 ; i <= edgeNum ; i++){
		scanf("%d %d",&tmpX,&tmpY);
		map[tmpX][tmpY] = 1;
		map[tmpY][tmpX] = 1;
	}

	queue[rear] = 1;
	rear++;
	check[1] =1.;
	/*
	printf("MAP#################################\n");
	for(int i = 1 ; i <= comNum; i++){
		for(int j = 1 ; j <= comNum; j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
*/
	while(front < rear){
		tmpX = queue[front];
		front++;

		for(int i = 1 ; i <= comNum; i++){
			if(map[tmpX][i] == 1 && check[i] == 0){
				check[i] = 1;
				queue[rear] = i;
				rear++;
			}
		}
	}
	/*
	printf("check#################################\n");
	for(int i = 1 ; i <= comNum; i++){
		printf("%d ",check[i]);
	}
	printf("\n\n");
	*/
	for(int i = 2 ; i <= comNum; i++){
		if(check[i] == 1){
			count++;
		}

	}
	printf("%d",count);



}