#include <stdio.h>
#pragma warning(disable:4996)

int n;
long long d[91];

int main()
{
	scanf("%d", &n);

	d[1] = 1;
	d[2] = 1;
	d[3] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	printf("%lld", d[n]);
}
