#include <stdio.h>
#pragma warning(disable:4996)

void input();
int check(int x, int y);

int n, m;
int map[302][302];
int tmpMap[302][302];
int visit[302][302] = {0};

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };

int q[100000][2];
int front = 0, rear = 0;
int tmpX, tmpY;
int currentX, currentY;
int result = 0;;
int cnt = 0;

int count(){
	front = 0, rear = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (cnt > 1) {
			break;
		}
		for (int j = 0; j < m; j++) {
			if (cnt > 1) {
				break;
			}
			if (map[i][j] > 0 && visit[i][j] ==0) {
				q[rear][0] = i;
				q[rear][1] = j;
				rear++;
				cnt++;
				//printf("cnt(%d,%d) = %d\n", i, j, cnt);
				visit[i][j] = 1;
				while (front < rear) {
					currentX = q[front][0];
					currentY = q[front][1];
					front++;
					
					for (int i = 0; i < 4; i++) {
						tmpX = currentX + dirX[i];
						tmpY = currentY + dirY[i];
						//printf("map(%d,%d) = %d  visit = %d\n", tmpX, tmpY, map[tmpX][tmpY], visit[tmpX][tmpY]);
						if (check(tmpX, tmpY) && map[tmpX][tmpY] > 0 && visit[tmpX][tmpY] == 0) {
							
							q[rear][0] = tmpX;
							q[rear][1] = tmpY;
							rear++;
							visit[tmpX][tmpY] = 1;
						}
					}				
				}			
			}
		}
	}
	return cnt;
}

int main()
{
	int printFlag = 0;
	input();
	
	while (1){
		int flag = count();
		if (flag> 1) {
			break;
		}
		result++;

		int sum = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum += map[i][j];
			}
		}
		if (sum == 0) {
			printf("0");
			printFlag++;
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cnt = 0;

				if (map[i][j] > 0) {
					for (int k = 0; k < 4; k++) {
						
						if (map[i + dirX[k]][j + dirY[k]] <= 0 && check(i + dirX[k], j + dirY[k])) {
							cnt++;
						}
						tmpMap[i][j] = map[i][j] - cnt;
						if (tmpMap[i][j] < 0) {
							tmpMap[i][j] = 0;
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = tmpMap[i][j];
				visit[i][j] = 0;
			}
		}
	}
	
	if (printFlag == 0) {
		printf("%d", result);
	}
	
}

void input()
{

	scanf("%d %d", &n,&m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d",&map[i][j]);
			tmpMap[i][j] = map[i][j];
		}
	}


}

int check(int x, int y) {

	if (x >= 0 && x < n && y >= 0 && y < m) {
		return 1;
	}
	else {
		return 0;
	}

}


/*

5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

5 7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0


5 5
1 1 1 1 1 
1 1 1 1 1 
1 1 0 1 1 
1 1 1 1 1 
1 1 1 1 1 



5 7
0 0 0 0 0 0 0
0 0 0 3 0 0 0
0 3 0 0 5 2 0
0 7 0 2 0 0 0
0 0 0 0 0 0 0

--> 섬의개수 : 4


*/