#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
int r,c, d;
int map[51][51];
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0,1,0,-1 };
int count = 0;
int tmpD;
int tmpX, tmpY;
int flag = 0;

int main() 
{
	scanf("%d %d", &n, &m);

	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (1) {
		if (map[r][c] == 0) {
			map[r][c] = 2 + count;////////////여기 +count 제거 필수
			count++;
		}
		

		for (int i = 1 ; i < 5; i++) {
			
			tmpD = ((d+4)-i)%4;
			
			tmpX = r + dirX[tmpD];
			tmpY = c + dirY[tmpD];
			if (map[tmpX][tmpY] == 0) {
				//printf("d = (%d)\n", tmpD);
				r = tmpX;
				c = tmpY;
				d = tmpD;
				break;
			}
			flag++;
		}
		//printf("FLAG == %d\n", flag);
		//printf("map[r+(tmpD+2)%4][c + (tmpD + 2) % 4]\n");
		//printf("map[%d][%d] =%d \n", r + (tmpD + 2) % 4, c + (tmpD + 2) % 4, map[r + (tmpD + 2) % 4][c + (tmpD + 2) % 4]);
		if (flag == 4 && map[r + dirX[(tmpD + 2) % 4]][c + dirY[(tmpD + 2) % 4]] == 1) {
			break;
		}
		if (flag == 4 && map[r + dirX[(tmpD + 2) % 4] ][c + dirY[(tmpD + 2) % 4]] >= 2) {
			r = r + dirX[(tmpD + 2) % 4];
			c = c + dirY[(tmpD + 2) % 4];
		}

		flag = 0;
	
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%2d ", map[i][j]);
		}
		//printf("\n");
	}


	printf("%d", count);

}
//d -> 0북 1동 2남 3서