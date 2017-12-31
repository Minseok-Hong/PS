#include <stdio.h>
#pragma warning(disable:4996)

int max(int a, int b);

int n;
int a[10001];
int d[10001][3];
int result = 0;

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;

	for (int i = 1; i <= n; i++) {
	
		d[i][0] = max (d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	
	}

	result = max(d[n][0], max(d[n][1], d[n][2]));

	printf("%d",result);
}

int max(int a, int b){
	
	if (a > b) {
		return a;
	}
	else {
		return b;
	}

}


/*
6
6
10
13
9
8
1


*/