#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
int map[51][51];
int result=0;

int tmpResult;
int target;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			target = map[i][j];

			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					if ( map[i][j] == map[k][j] && map[i][j] == map[i][l] && map[i][j] == map[k][l] && (k - i)*(k - i) == (j - l)*(j - l)) {
						tmpResult = (j - l+1)*(j - l+1);
						//printf("(%d, %d) , (%d, %d)\n", i, j, k, l);
						if (tmpResult > result) {
							result = tmpResult;
						
						}
					}
				
				}
			
			}
		}
	}



	printf("%d", result);
}