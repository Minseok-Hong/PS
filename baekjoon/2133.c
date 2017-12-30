#include <stdio.h>
#pragma warning(disable:4996)

int n;
int d[30];

int main()
{
	scanf("%d", &n);

	d[0] = 1;
	d[1] = 0;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] += 3 * d[i - 2];
		for (int j = 4; j <= i; j +=2) {
			d[i] += 2*d[i - j];			
		}
		
	}
	printf("%d", d[n]);
}
/*

8 ->153
*/