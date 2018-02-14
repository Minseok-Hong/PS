#include <stdio.h>
#pragma warning(disable:4996)

int n;
int num[12];
int cal[4];
long long max=-1000000000, min= 1000000000;

void input();

void dfs(int a, int b, int c, int d, long long sum, int cnt)
{
	//printf("dfs(%d,%d,%d,%d,%lld, %d)\n", a, b, c, d, sum, cnt);
	if (cnt == n-1) {
		//printf("sum : %d\n",sum);
		//printf("max : %d\n",max);
		//printf("min : %d\n",min);
		if (sum > max) {
			max = sum;
		}
		if (sum < min) {
			min = sum;
		}
	}

	if (a > 0) { dfs(a - 1, b, c, d, sum + num[cnt + 1], cnt + 1); }
	if (b > 0) { dfs(a, b - 1, c, d, sum - num[cnt + 1], cnt + 1); }
	if (c > 0) { dfs(a, b, c - 1, d, sum * num[cnt + 1], cnt + 1); }
	if (d > 0) { dfs(a, b, c, d - 1, sum / num[cnt + 1], cnt + 1); }

}

int main()
{
	input();

	dfs(cal[0], cal[1], cal[2], cal[3], num[0], 0);

	printf("%lld\n", max);
	printf("%lld\n", min);
}

void input() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &cal[i]);
	}

}

/*


6
1 2 3 4 5 6
2 1 1 1

*/