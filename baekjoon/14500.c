#include <stdio.h>
#pragma warning(disable:4996)

int max(int a, int b);
int check(int x, int y);
void init();

int n,m;
int map[501][501];
int tmpMap[501][501] = {0};
int visit[501][501];

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };
int currentX, currentY;
int tmpX, tmpY;
int tmpSum=0;
int result=0;
int tmpResult = 0;


void exception(int x, int y) {
	int sum=map[x][y];
	int cnt = 0;
	
	for (int i = 0; i < 4; i++) {
		tmpX = x + dirX[i];
		tmpY = y + dirY[i];
		if (check(tmpX, tmpY)) {
			cnt++;
			sum = sum + map[tmpX][tmpY];
		}
	}
	if (cnt == 4) {
		for (int i = 0; i < 4; i++) {
			tmpX = x + dirX[i];
			tmpY = y + dirY[i];
			if (tmpResult < sum - map[tmpX][tmpY]) {
				tmpResult = sum - map[tmpX][tmpY];
			}
		}
	}
	else if (cnt == 3) {
		if (tmpResult < sum) {
			tmpResult = sum;
		}
	
	}


}

int dfs(int x, int y, int cnt, int sum) {
	//printf("cnt = %d map == %d  sum = %d\n", cnt,map[x][y], sum);
	if (cnt == 4) {
		visit[x][y] = 1;

		if (sum > tmpResult) {
			tmpResult = sum ;
			//printf("tmpResult =%d\n", tmpResult);
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", visit[i][j]);
				if (visit[i][j] == 1) {
					tmpSum = tmpSum + map[i][j];
				}
			}
			printf("\n");
		}
		printf("RESULT = %d\n", tmpSum);
		printf("\n\n");
		*/
		if (tmpSum > result) {
			result = tmpSum ;
			
		}
		tmpSum = 0;
		visit[x][y] = 0;
		return 0;
	}
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		tmpX = x + dirX[i];
		tmpY = y + dirY[i];
		if (check(tmpX, tmpY)) {
			dfs(tmpX, tmpY, cnt + 1,sum + map[tmpX][tmpY]);
		}
	}
	visit[x][y] = 0;
}



int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("================\n");
			visit[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			exception(i, j);
			visit[i][j] = 0;
		}
	}

	//printf("result= %d\n", result);
	printf("%d", tmpResult);
	

}

void init(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmpMap[i][j] = 0;
		}
	}

}

int check(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m&& visit[x][y]==0) {
		return 1;
	}
	else {
		return 0;
	}


}
int max(int a, int b) {

	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}