#include <stdio.h>
#pragma warning(disable:4996)

void input();
void output();

int n;
int map[101][101];
int check[101] = {0};
int result[101][101];

int queue[100000];
int front = 0, rear = 0;
int tmpI, tmpJ;

int main()
{
	input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[j] != 1) {
				queue[rear] = j;
				check[j] = 1;
				result[i][j] = 1;
				rear++;
				//output();
				//printf("(%d,%d)\n", i, j);
			}
		}
		//printf("\n\n");
		while (front < rear) {
			tmpI = queue[front];
			front++;

			for (int j = 0; j < n; j++) {
				if (map[tmpI][j] == 1 && check[j] != 1) {
					//printf("(%d,%d)\n", tmpI, j);
					queue[rear] = j;
					check[j] = 1;
					result[i][j] = 1;
					rear++;
					//output();
				}
			}
			
		}
		front = 0, rear = 0;
		for (int i = 0; i < n; i++) {
			check[i] = 0;
		}

	}
	output();
}

void input()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			result[i][j] = 0;
		}
	}
}

void output()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}