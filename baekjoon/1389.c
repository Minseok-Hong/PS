#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
int map[102][102] = {0};
int tmp1, tmp2;
int visit[102] = {0};
int result[102] = { 0 };
int q[100000];
int front = 0, rear = 0;
int tmp;
int cnt = 1;
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		map[tmp1][tmp2] = 1;
		map[tmp2][tmp1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		cnt = 1;
		front = 0, rear = 0;

		for (int j = 1; j <= n; j++) {
			//printf("n = %d\n", n);
			//printf("(%d,%d) = %d\n", i, j, map[i][j]);
			if (map[i][j] == 1) {
				//printf("%d ", j);
				q[rear] = j;
				visit[j] = cnt;
				rear++;
			}
		}
		for (int j = 1; j <= n; j++) {
			while (front < rear) {
				tmp = q[front];
				front++;

				for (int k = 1; k <= n; k++) {
					if (map[tmp][k] == 1 && visit[k] == 0) {
						//printf("%d ", k);
						q[rear] = k;
						visit[k] = visit[tmp]+1;
						rear++;
					}
				}
			}
			
		}
		//printf("Num(%d)=============\n", i);
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;

			//printf("(%d,%d) = %d\n", i, j, visit[j]);
			result[i] += visit[j];
			visit[j] = 0;
		}
		//printf("Num(%d) = %d\n", i, result[i]);
	}
	for (int i = 1; i <= n; i++) {
		//printf("Num(%d) = %d\n",i, result[i]);
	}
	int ret= 101;
	int ret2;
	for (int i = 1; i <= n; i++) {
		if (ret > result[i]) {
			ret = result[i];
			ret2 = i;
		}
	
	}
	printf("%d", ret2);
}
/*
5 5
1 3
1 4
2 3
3 4
4 5




*/