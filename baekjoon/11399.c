#include <stdio.h>
#pragma warning(disable:4996)

void input();

int n;
int tmp;
int p[1001];
int sum[1001] = {0};
int result = 0;


int main()
{
	input();

	for (int i = 0; i < n; i++) {
		//printf("%d ", p[i]);
	}
	//printf("\n\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (p[j] > p[j + 1]) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		
		}
	}

	for (int i = 0; i < n; i++) {
		//printf("%d ", p[i]);
	}
	//printf("\n\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum[i] += p[j];
		}
		result += sum[i];
	}
	for (int i = 0; i < n; i++) {
		//("%d ", sum[i]);
	}
	//printf("\n\n");


	printf("%d", result);
}


void input()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

}