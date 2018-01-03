#include <stdio.h>
#pragma warning(disable:4996)

int n;
int d[1002];

int main()
{
	scanf("%d", &n);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;

	for (int i = 4; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2])%10007;
	
	}

	printf("%d", d[n] % 10007);



}