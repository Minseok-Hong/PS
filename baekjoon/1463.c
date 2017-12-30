#include <stdio.h>
#pragma warning(disable:4996)

int n;
int map[1000001];


int go(int x) {

	if (x == 1)
		return 0;
	if (map[x] > 0) {
		return map[x];
	}
	map[x] = go(x - 1) + 1;
	if (x % 3 == 0) {
		int tmp = go(x / 3) + 1;
		if (tmp < map[x]) {
			map[x] = tmp;
		}
		
	}
	if (x % 2 == 0) {
		int tmp = go(x / 2) + 1;
		if (tmp < map[x]) {
			map[x] = tmp;
		}
		
	}

	return map[x];

}
int main()
{
	int result;

	scanf("%d", &n);

	result = go(n);

	printf("%d", result);


}


/*
#include <stdio.h>
#pragma warning(disable:4996)

int n;
int queue[1000000001];
int front = 0, rear = 0;
int tmp;
int map[10000001] = {0};


int main()
{
	scanf("%d", &n);

	if (n == 1) {
		printf("0");
	}
	
	if (n % 3 == 0 && n / 3 >=1) {
		if (map[n / 3] == 0) {
			map[n / 3] = map[n] + 1;
			queue[rear] = n / 3;
			rear++;
		}
	}
	if (n % 2 == 0 && n / 2 >=1) {

		if (map[n / 2] == 0) {
			map[n / 2] = map[n] + 1;
			queue[rear] = n / 2;
			rear++;
		}
		
	}
	if (n - 1 >= 1) {
		if (map[n - 1] == 0) {
			map[n - 1] = map[n] + 1;
			queue[rear] = n - 1;
			rear++;
		}
		
	}
	

	while (map[1] == 0)
	{
		
		tmp = queue[front];
		front++;

		if (tmp % 3 == 0 && tmp / 3 >=1) {
			if (map[tmp / 3] == 0) {
				map[tmp / 3] = map[tmp] + 1;
				queue[rear] = tmp / 3;
				rear++;
			
			}
			
		}
		if (tmp % 2 == 0 && tmp / 2 >= 1) {
			if (map[tmp / 2] == 0) {
				map[tmp / 2] = map[tmp] + 1;
				queue[rear] = tmp / 2;
				rear++;
			}
			
		}
		if (n - 1 >= 1) {
			if (map[tmp - 1] == 0) {
				map[tmp - 1] = map[tmp] + 1;
				queue[rear] = tmp - 1;
				rear++;
			
			}
			
		}

	}
	for (int i = 1; i <= n; i++) {
		//printf("%d ", map[i]);
	}
	
	if (n != 1) {
		printf("%d", map[1]);
	}
	
}*/