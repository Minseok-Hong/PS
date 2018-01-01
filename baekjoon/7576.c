#include <stdio.h>
#define MAXSIZE 1100

int rowCount, colCount;
int map[MAXSIZE][MAXSIZE];
int queue [MAXSIZE*MAXSIZE][2], visit[MAXSIZE][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int front= 0, rear =0;
int check[MAXSIZE][MAXSIZE];
int day = 0;
int count =0;
int tmpX, tmpY;

int main()
{
	scanf("%d %d", &colCount, &rowCount);

	for(int i = 0 ; i <= rowCount+1; i++){
			for(int j = 0 ; j <= colCount+1 ; j++){
				map[i][j] = -1;
				check[i][j] = 0;
		}
	}//initialize
	for(int i = 1 ; i <= rowCount; i++){
		for(int j = 1 ; j <= colCount; j++){
			scanf("%d",&map[i][j]);	
			if(map[i][j] == 1){
				queue[rear][0]=i;
				queue[rear][1]=j;
				rear++; 
			}
		}
	}//input

	while(front < rear){
		tmpX = queue[front][0];
		tmpY = queue[front][1];
		front++;

		for(int i = 0 ; i<4; i++){
			if(map[tmpX+dx[i]][tmpY+dy[i]] == 0){
				map[tmpX+dx[i]][tmpY+dy[i]] = 1;
				check[tmpX+dx[i]][tmpY+dy[i]] = check[tmpX][tmpY] +1;
				queue[rear][0]=tmpX+dx[i];
				queue[rear][1]=tmpY+dy[i];
				rear++; 
			}
		}
		/*printf("map#################################\n");
		for(int i = 0 ; i <= rowCount+1; i++){
			for(int j = 0 ; j <= colCount+1 ; j++){
				printf("%d ",map[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		printf("check#################################\n");
		for(int i = 0 ; i <= rowCount+1; i++){
			for(int j = 0 ; j <= colCount+1 ; j++){
				printf("%d ",check[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		*/
	}
	for(int i = 0 ; i <= rowCount+1; i++){
		for(int j = 0 ; j <= colCount+1 ; j++){
			if(check[i][j]>day){
				day	= check[i][j];
			}
		}
		
	}
	for(int i = 1 ; i <= rowCount; i++){
		for(int j = 1 ; j <= colCount ; j++){
			if(map[i][j] ==0){
				count = -1;
			}
		}	
	}
	if(count==-1){
		printf("%d",count);
	}
	else{
		printf("%d",day);
	}
	
}
