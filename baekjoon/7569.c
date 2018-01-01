#include <stdio.h>
#define MAXSIZE 110

int rowCount, colCount, height;
int map[MAXSIZE][MAXSIZE][MAXSIZE];
int queue [MAXSIZE*MAXSIZE*MAXSIZE][3];
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};
int front= 0, rear =0;
int check[MAXSIZE][MAXSIZE][MAXSIZE];
int day = 0;
int count =0;
int tmpX, tmpY, tmpZ;

int main()
{
	scanf("%d %d %d", &colCount, &rowCount,&height);

	for(int i = 0 ; i <= rowCount+1; i++){
		for(int j = 0 ; j <= colCount+1 ; j++){
			for(int k = 0 ; k <= height+1; k++){
				map[i][j][k] = -1;
				check[i][j][k] = 0;
			}
		}
	}//initialize
	for(int k = 1 ; k <= height; k++){
        for(int i = 1 ; i <= rowCount; i++){
           for(int j = 1 ; j <= colCount; j++){
				scanf("%d",&map[i][j][k]);	
				if(map[i][j][k] == 1){
					queue[rear][0]=i;
					queue[rear][1]=j;
					queue[rear][2]=k;
					rear++; 
				}
			}
		}
		//printf("! ");
	}//input
	//printf("@ ");
	while(front < rear){
		tmpX = queue[front][0];
		tmpY = queue[front][1];
		tmpZ = queue[front][2];

		front++;

		for(int i = 0 ; i<6; i++){
			if(map[tmpX+dx[i]][tmpY+dy[i]][tmpZ+dz[i]] == 0){
				map[tmpX+dx[i]][tmpY+dy[i]][tmpZ+dz[i]] = 1;
				check[tmpX+dx[i]][tmpY+dy[i]][tmpZ+dz[i]] = check[tmpX][tmpY][tmpZ] +1;
				queue[rear][0]=tmpX+dx[i];
				queue[rear][1]=tmpY+dy[i];
				queue[rear][2]=tmpZ+dz[i];
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
			for(int k = 0 ; k<=height+1; k++){
				if(check[i][j][k]>day){
					day	= check[i][j][k];
				}
			}
		}
		
	}
	for(int i = 1 ; i <= rowCount; i++){
		for(int j = 1 ; j <= colCount ; j++){
			for(int k = 1 ; k<=height; k++){
				if(map[i][j][k] ==0){
					count = -1;
				}
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
