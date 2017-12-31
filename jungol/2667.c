#include <stdio.h>
#define MAXSIZE 30

int number;
int map[MAXSIZE][MAXSIZE];
int check[MAXSIZE][MAXSIZE];
int queue[MAXSIZE*MAXSIZE][2];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int tmpX, tmpY;
int currentX, currentY;
int front = 0 , rear = 0;
int max[MAXSIZE*MAXSIZE] = {0};
int maxIndex = 0;
int count;
int temp;

int BFS (int x, int y){

	queue[rear][0] = x;
	queue[rear][1] = y;
	check[x][y] = 1;
	rear++;
	count++;
	//printf("(%d,%d) COUNT : %d \n",x,y,count);

	while(front < rear){
		currentX = queue[front][0];
		currentY = queue[front][1];
		//count++;
		front++;

		for(int i = 0 ; i < 4; i++){
			tmpX = currentX + dx[i];
			tmpY = currentY + dy[i];
	
				if(map[tmpX][tmpY] == 1 && check[tmpX][tmpY] == 0){
					check[tmpX][tmpY] = check[currentX][currentY] + 1;
					queue[rear][0] = tmpX;
					queue[rear][1] = tmpY;
					rear++;	
					count++;
					//printf("(%d,%d) COUNT : %d \n",tmpX,tmpY,count);
				}
		}
	}
	return count;
}

int main()
{
	scanf("%d",&number);

	for(int i = 0 ; i <= number+1; i++){
		for(int j = 0 ; j <= number+1; j++){
			map[i][j] = -1;
			check[i][j] = 0;
		}	
	}//initialization

	for(int i = 1 ; i <= number; i++){
		for(int j = 1 ; j <= number; j++){
			scanf("%1d",&map[i][j]);
		}	
	}//input

	for(int i = 1 ; i <= number; i++){
		for(int j = 1 ; j <= number; j++){
			if(map[i][j] == 1 && check[i][j] == 0){
				max[maxIndex] = BFS(i,j);
				maxIndex++;
				count = 0;
			}
		}	
	}
	printf("%d\n",maxIndex );

	for(int i = 0 ; i <maxIndex-1 ; i++){
		for(int j = 0 ; j < maxIndex-i-1 ; j++){
			if(max[j]>max[j+1]){
				temp = max[j];
				max[j] = max[j+1];
				max[j+1] = temp;
			}
		}
	}
	for(int i = 0 ; i < maxIndex; i++ ){
		printf("%d\n",max[i]);
	}




}