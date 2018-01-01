#include <stdio.h>
#pragma warning(disable:4996)

int T;
int n[1000];

int d[12];

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &n[i]);
	}
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;// 1+1, 2
	d[3] = 4;//1+1+1, 2+1, 1+2, 3

	for(int i = 4; i <= 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		//printf("d[%d] = %d\n", i, d[i]);
	}

	for(int i = 0; i < T; i++) {
		printf("%d\n", d[n[i]]);
	}
}