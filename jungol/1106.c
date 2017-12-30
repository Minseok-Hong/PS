#include <stdio.h>
#pragma warning(disable:4996)
 
int check(int y, int x);
 
int n,m;
int map[110][110];
int visit[110][110] = {0};
 
 
int dirY[8] = { -1,-2,-2,-1,1,2,2,1 };
int dirX[8] = { -2,-1, 1, 2,2,1,-1,-2 };
 
int q[1000000][2];
int front = 0, rear = 0;
int tmpX, tmpY;
int currentX, currentY;
 
int r, c;//말
int s, k;//졸
 
int main()
{
    scanf("%d %d", &m, &n);
    scanf("%d %d", &r, &c);
    scanf("%d %d", &s, &k);
 
    q[rear][0] = c;
    q[rear][1] = r;
    rear++;
 
    while (front < rear){
 
        currentY = q[front][0];
        currentX = q[front][1];
        front++;
         
        //printf("visit(%d,%d) =%d\n", currentY, currentX,visit[currentY][currentX]);
 
        if (currentY == k && currentX == s) {
            printf("%d", visit[currentY][currentX]);
            break;
        }
 
        for (int i = 0; i < 8; i++) {
            tmpY = currentY + dirY[i];
            tmpX = currentX + dirX[i];
            if (check(tmpY, tmpX) == 1 && visit[tmpY][tmpX] == 0) {
                q[rear][0] = tmpY;
                q[rear][1] = tmpX;
                visit[tmpY][tmpX] = visit[currentY][currentX] + 1;
                rear++;
            }
 
        }
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //printf("%d ", visit[i][j]);
            }
            //printf("\n");
        }
        //printf("\n\n");
    }
     
 
}
 
int check(int y, int x) {
 
    if (y > 0 && y <= n&& x > 0 && x <= m&&visit[y][x] == 0) {
        return 1;
 
    }
    else {
        return 0;
    }
 
}
 
/*
9 9
3 5 2 8
 
-->2
 
 
 
100 73
28 21 91 32
 
-->32
*/
 
 
 
 
 
 
 
 
 
 
 
 
 
/*
int n, m;
int r, c;//말의위치
int s, k;//졸의 위치
int dirX[8] = {-2,-1,1,2,2,1,-1,-2};
int dirY[8] = {-1,-2,-2,-1,1,2,2,1};
int checkMap[101][101] = {0};
 
int queue[100000][2];
int front = 0, rear = 0;
int currentX, currentY;
int tmpX, tmpY;
int count = 0;
 
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d", &r, &c);
    scanf("%d %d", &s, &k);
 
    queue[rear][0] = r;
    queue[rear][1] = c;
    rear++;
 
    while (front < rear){
 
        currentX = queue[front][0];
        currentY = queue[front][1];
        front++;
        //count++;
        //checkMap[currentX][currentY] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //printf("%d ", checkMap[i][j]);
            }
            //printf("\n");
        }
 
        //printf("current = (%d,%d)\n", currentX, currentY);
        if (currentX == s && currentY == k) {
            checkMap[s][k] = checkMap[currentX][currentY];
            //printf("(%d,%d)\n", currentX, currentY);
            break;
        }
 
        for (int i = 0; i < 8; i++) {
            tmpX = currentX + dirX[i];
            tmpY = currentY + dirY[i];
            //printf("current = (%d,%d)\n", currentX, currentY);
            if (tmpX > 0 && tmpX <= n && tmpY > 0 && tmpY <= m && checkMap[tmpX][tmpY] ==0 ) {
                queue[rear][0] = tmpX;
                queue[rear][1] = tmpY;
                checkMap[tmpX][tmpY] = checkMap[currentX][currentY] + 1;
                rear++;
             
            }
         
        }
 
    }
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            //printf("%d ", checkMap[i][j]);
        }
        //printf("\n");
    }
    printf("%d", checkMap[s][k]);
 
}*/
