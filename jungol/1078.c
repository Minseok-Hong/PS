#include <stdio.h>
#pragma warning(disable:4996)
 
int max();
int survive();
 
int n, m;
int r, c;
int map[102][102];
int visit[102][102] = { 0 };
 
int q[100000][2];
int front = 0, rear = 0;
int currentX, currentY;
int tmpX, tmpY;
 
int dirX[4] = {0,0,1,-1};
int dirY[4] = {1,-1,0,0};
 
int main()
{
    scanf("%d %d", &m, &n);//// m은 가로 n은 세로
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
 
    scanf("%d %d", &r, &c);// r은 가로 c는 세로
 
    q[rear][0] = c;
    q[rear][1] = r;
    rear++;
    visit[c][r] = 3;
    map[c][r] = 0;
 
    while (front < rear)
    {
        currentY = q[front][0];
        currentX = q[front][1];
        front++;
 
        //("(%d,%d)\n", currentY, currentX);
        for (int i = 0; i < 4; i++) {
            tmpY = currentY + dirY[i];
            tmpX = currentX + dirX[i];
 
            if (tmpX > 0 && tmpX <= m && tmpY > 0 && tmpY <= n && map[tmpY][tmpX] == 1 && visit[tmpY][tmpX] == 0) {
                q[rear][0] = tmpY;
                q[rear][1] = tmpX;
                visit[tmpY][tmpX] = visit[currentY][currentX] + 1;
                map[tmpY][tmpX] = 0;
                rear++;
            }
        }
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //printf("%d ", visit[i][j]);
            }
            //printf("\n");
        }
        //printf("\n");
 
    }
 
 
    int result = max();
    printf("%d\n",result);
 
    int survi = survive();
    printf("%d\n", survi);
}
 
int max()
{
    int max = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visit[i][j] >= max) {
                max = visit[i][j];
            }
        }
    }
 
    return max;
 
}
 
int survive()
{
    int count=0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
 
}
