#include <stdio.h>
#pragma warning(disable:4996)

int min(int a, int b);

int n;
int a[1001][3];
int d[1001][3];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {// 0 R, 1 G, 2 B
		for (int j = 0; j < 3; j++) {// home Number
			scanf("%d", &a[i][j]);
		}
	}

	d[1][0] = a[1][0];
	d[1][1] = a[1][1];
	d[1][2] = a[1][2];

	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i - 1][1] + a[i][0], d[i - 1][2] + a[i][0]);
		d[i][1] = min(d[i - 1][0] + a[i][1], d[i - 1][2] + a[i][1]);
		d[i][2] = min(d[i - 1][0] + a[i][2], d[i - 1][1] + a[i][2]);
	
	}
	int result = min(d[n][0], min(d[n][1], d[n][2]));
	printf("%d", result);

}


int min(int a, int b) {

	if (a < b) {
		return a;
	}
	else {
		return b;
	}


}













	/*
	d[0][0] = a[0][0];
	d[0][1] = a[0][1];
	d[0][2] = a[0][2];

	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	
	}

	printf("%d", min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2])));
	//d[n - 1][0] 
	//d[n - 1][1]   
	//d[n - 1][2]


}*/
