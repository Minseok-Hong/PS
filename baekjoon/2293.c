#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 101

int number;
int target;
int tmpTarget;
int coin[MAX];
int count = 0;
int cache[10001] = { 0, };

void input()
{
	scanf("%d %d", &number, &target);

	tmpTarget = target;

	for (int i = 0; i < number; i++) {
		scanf("%d", &coin[i]);
	}
}
void sort() 
{
	int tmp;

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number-1; j++) {
			if (coin[j] > coin[j+1]) {
				tmp = coin[j];
				coin[j] = coin[j+1];
				coin[j+1] = tmp;
			}
		}
	}
}


int main()
{
	int index=0;

	input();
	sort();

	cache[0] = 1;

	for (int i = 0; i < number; i++) {
		for (int j = 0; j <= target; j++) {
			if (j >= coin[i]) {
				//printf("j >= coin[i]\n %d      %d\n", j, coin[i]);
				cache[j] += cache[j - coin[i]];
				//printf("cache[j] += cache[j - coin[i]]\n %d  += %d\n\n", cache[j], cache[j - coin[i]]);
			}
		}
	}

	for (int i = 0; i < target; i++) {
		//printf("%d ", cache[i]);
	}
	//printf("\n");
	printf("%d", cache[target]);


}