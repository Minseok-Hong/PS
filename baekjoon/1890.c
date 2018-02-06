#include <stdio.h>
#pragma warning(disable:4996)

int n;
int map[1001][1001];
//int check[1001][1001] = {0};
int q[100000000][2];
int front = 0, rear = 0;
int tmpX, tmpY, tmpValue;
int currentX, currentY;
long long result = 0;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	q[rear][0] = 0;
	q[rear][1] = 0;
	//check[0][0] = 1;
	rear++;

	while (front < rear){
		tmpX = q[front][0];
		tmpY = q[front][1];
		front++;
		//printf("(%d,%d)\n", tmpX, tmpY);
		
		if (tmpX == n-1 && tmpY == n-1) {
			result++;
			continue;
		}
		tmpValue = map[tmpX][tmpY];

		currentX = tmpX + tmpValue;
		
		if (currentX < n /*&& check[currentX][tmpY] ==0*/) {
			q[rear][0] = currentX;
			q[rear][1] = tmpY;
			rear++;
			//check[currentX][tmpY] = 1;
		}

		currentY = tmpY + tmpValue;
		if (currentY < n /*&& check[tmpX][currentY] == 0*/) {
			q[rear][0] = tmpX;
			q[rear][1] = currentY;
			rear++;
			//check[tmpX][currentY] = 1;
		}
	}
	printf("%lld", result);

}

/*

4
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0

*/