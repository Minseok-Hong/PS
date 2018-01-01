#include <stdio.h>
#pragma warning(disable:4996)

int max(int a, int b);

int n;
int p[1001];
int d[1001];

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	d[0] = 0;
	d[1] = p[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}

	printf("%d", d[n]);
}

int max(int a, int b) {

	if (a > b) {
		return a;
	}
	else
		return b;
}