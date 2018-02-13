#include<stdio.h>
#pragma warning(disable:4996)

int t;
int m, n;
int k;
int x, y;
int map[51][51];
int check[51][51];
int count = 1;

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };

int front = 0, rear = 0;
int q[100000][2];
int tmpX, tmpY;
int currentX, currentY;

void init() {

	count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

void bfs(){

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				q[rear][0] = i;
				q[rear][1] = j;
				rear++;
				check[i][j] = count;

				while (front <rear){
					tmpX = q[front][0];
					tmpY = q[front][1];
					front++;

					for (int k = 0; k < 4; k++) {
						currentX = tmpX + dirX[k];
						currentY = tmpY + dirY[k];

						if (currentX >= 0 && currentX < n && currentY >= 0 && currentY < m && map[currentX][currentY] == 1 && check[currentX][currentY] == 0) {
							q[rear][0] = currentX;
							q[rear][1] = currentY;
							rear++;
							check[currentX][currentY] = count;
						}
					}

				}
				count++;
			}
		}
	}
}

int main(){

	scanf("%d", &t);

	for (int l = 0; l < t; l++) {
		scanf("%d %d %d", &m, &n, &k);// n:col, m=row;
		init();
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);	// x =row, y=col
			map[y][x] = 1;
		}
		bfs();
	/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ",check[i][j]);
			}
			printf("\n");
		}
	*/
		printf("%d\n", count-1);
	}
}


/*

2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5



*/