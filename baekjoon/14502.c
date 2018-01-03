#include <stdio.h>

#pragma warning(disable:4996)

void init();
int count();

int n, m;
int map[9][9];
int tmpMap[9][9];
int check[9][9] = { 0 };

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0, };

int queue[100000][2];
int Rrear = 0;
int front, rear;
int currentX, currentY;
int tmpX, tmpY;
int tmpResult = 0;
int max =0;

void bfs() {

	while (front < rear)
	{
		currentX = queue[front][0];
		currentY = queue[front][1];
		front++;
		//printf("(%d,%d)\n", currentX, currentY);
		for (int i = 0; i < 4; i++) {
			tmpX = currentX + dirX[i];
			tmpY = currentY + dirY[i];

			if (tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < m && check[tmpX][tmpY] == 0 && tmpMap[tmpX][tmpY] == 0) {
				tmpMap[tmpX][tmpY] = 2;
				queue[rear][0] = tmpX;
				queue[rear][1] = tmpY;
				rear++;
				check[tmpX][tmpY] = 1;
			}
		}

	}

	front = 0, rear = Rrear;

}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			//tmpMap[i][j] = map[i][j];
			if (map[i][j] == 2) {
				queue[rear][0] = i;
				queue[rear][1] = j;
				rear++;
			
			}
		}
	}
	Rrear = rear;
	//printf("\n\n\n");
	for (int i = 0; i <= n*m; i++) {
		for (int j = i + 1; j <= n*m; j++) {
			for (int k = j + 1; k <= n*m; k++) {

				init();

				if (tmpMap[i / m][i%m] == 0 && tmpMap[j / m][j%m] == 0 && tmpMap[k / m][k%m] == 0) {
					tmpMap[i / m][i%m] = 1;
					tmpMap[j / m][j%m] = 1;
					tmpMap[k / m][k%m] = 1;
					//printf("(%d,%d) ", i / m, i%m);
					//printf("(%d,%d) ", j / m, j%m);
					//printf("(%d,%d) \n", k / m, k%m);

					bfs();
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							//printf("%d ", tmpMap[i][j]);

						}
						//printf("\n");
					}
					//printf("\n\n");

					tmpResult = count();
					//printf("MAX = %d\n", tmpResult);
				}

				if (tmpResult > max) {
					max = tmpResult;
					

	
				}
			}
		}
	}
	

	

	printf("%d", max);


}
int count() 
{
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpMap[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}


void init()
{

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmpMap[i][j] = map[i][j];
			check[i][j] = 0;
		}
	}
	
}

/*
7 7
2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0


*/