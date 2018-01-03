#include <stdio.h>
#pragma warning(disable:4996)

void input();

int n,m;
int map[1002][1002] = {0};
int visit[1001] = { 0 };
int input1, input2;
int result = 0;

void dfs(int x) {

	for (int i = 0; i <= n; i++) {
		if (visit[i] == 0&& map[x][i] ==1) {
			//printf("%d ",i);
			visit[i] = 1;
			dfs(i);
		}

	}
}

int main()
{
	input();

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			//printf("%d ",i);
			dfs(i);
			//printf("\n");
			result++;
		}
	}

	printf("%d", result);

}

void input()
{

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &input1, &input2);
		map[input1][input2] = 1;
		map[input2][input1] = 1;
	}

}