#include <stdio.h>
#pragma warning(disable:4996)

void input();

int n;
int map[501][501];
int check[502][502];
int queue[501][2];
int front = 0, rear = 0;
int tmpX, tmpY;
int right, left;

int main()
{
	input();

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j <= i; j++) {
			left = map[i][j] + check[i + 1][j];
			right = map[i][j] + check[i + 1][j + 1];
			//printf("(%d,%d)==(%d,%d)\n",i,j, left, right);
			if (map[i + 1][j] < left) {
				map[i + 1][j] = left;
			}
			if (map[i + 1][j+1] < right) {
				map[i + 1][j+1] = right;
			}
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/

	int max=0;

	for (int j = 0; j < n; j++) {
		if (map[n-1][j] > max) {
			max = map[n-1][j];
		}
	}

	printf("%d", max);

}

void input()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &map[i][j]);
			check[i][j] = map[i][j];
		}
	}

}