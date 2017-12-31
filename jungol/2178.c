#include <stdio.h>
#define MAXSIZE 110

int rowCount, colCount;
int map[MAXSIZE][MAXSIZE];
int check[MAXSIZE][MAXSIZE];
int queue[MAXSIZE*MAXSIZE][2];
int front = 0, rear = 0;
int currentCol = 0 , currentRow = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int inputTmp[MAXSIZE];
int count =0;

int main()
{
	scanf("%d %d",&rowCount,&colCount);

	for(int i =0; i<= rowCount+1; i++){
		for(int j = 0 ; j <= colCount+1; j++){
			map[i][j] = -1;
			check[i][j] = 0;
		}
	}//initialization
	//printf("\n%d\n",rowCount*colCount );

	for(int i =1; i<= rowCount; i++){
		for(int j = 1 ; j <= colCount; j++){
			scanf("%1d",&map[i][j]);
		}
	}
	//printf("##\n");
	queue[rear][0] = 1;
	queue[rear][1] = 1;
	check[1][1] = 1;
	rear++;
	/*
	for(int i =1; i<= rowCount; i++){
		for(int j = 1 ; j <= colCount; j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}*/
	//printf("PPPPPP %d \n",map[2][1]);
	while(front < rear){
		currentRow = queue[front][0];
		currentCol = queue[front][1];
		front++;

		for(int i = 0 ; i < 4; i++){
			if((map[currentRow+dx[i]][currentCol+dy[i]] == 1) && (check[currentRow+dx[i]][currentCol+dy[i]] == 0)){
				//printf("Point row : %d col : %d MAP : %d \n",currentRow+dx[i],currentCol+dy[i],map[currentRow+dx[i]][currentCol+dy[i]]);
				queue[rear][0] = currentRow+dx[i];
				queue[rear][1] = currentCol+dy[i];
				check[currentRow+dx[i]][currentCol+dy[i]] = check[currentRow][currentCol]+1;
				rear++;

			}
		}
		/*
		for(int i = 0 ; i < rear; i++){
			printf("(%d, %d)\n",queue[i][0],queue[i][1] );	
		}
		
		for(int i =1; i<= rowCount; i++){
			for(int j = 1 ; j <= colCount; j++){
				printf("%d ",check[i][j]);
			}
		printf("\n");
		}
		printf("\n\n");
*/

	}
	//printf("@@\n");
	

	printf("%d\n",check[rowCount][colCount]);


}