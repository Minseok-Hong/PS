#include <stdio.h>

#pragma warning(disable:4996)
#define MAXSIZE 100001

int start;
int target;
int check[MAXSIZE] = {0};
int distance[MAXSIZE] = {0};

int queue[MAXSIZE];
int front = 0, rear = 0;

int tmp;
int move[3];//before, next, jump;

int main()
{
	scanf("%d %d", &start, &target);
	check[start] = 1;

	queue[rear] = start;
	check[start] = 1;
	distance[start] = 0;
	rear++;

	while (front < rear) {
		tmp = queue[front];

		//printf("TMP == %d,  cost == %d\n", tmp, distance[tmp]);
		front++;

		if (tmp == target) {
			//printf("\n============\n");
			//printf("TMP == %d,  cost == %d\n", tmp, distance[tmp]);
			printf("%d", distance[tmp]);
			break;
		}
		
		move[0] = tmp - 1;
		move[1] = tmp + 1;
		move[2] = tmp * 2;

		for (int i = 0; i < 3; i++) {
		
			if (move[i] >= 0 && move[i] <= 100000 && check[move[i]] == 0) {
				queue[rear] = move[i];
				check[move[i]] = 1;
				distance[move[i]] = distance[tmp] + 1;
				rear++;

			}

		}
	
	}


}