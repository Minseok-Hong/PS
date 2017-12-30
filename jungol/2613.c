/**************************************************************
    Problem: 2613
    User: hong4243
    Language: C
    Result: Success
    Time:149 ms
    Memory:16748 kb
****************************************************************/
 
 
#include <stdio.h>
#pragma warning(disable:4996)
 
void input();
int mapCheck();
int maxVisit();
int check(int y, int x);
 
int n, m;
int map[1002][1002];
int visit[1002][1002] = { 0 };
 
int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };
 
int q[1000000][2];
int front = 0, rear = 0;
int currentX, currentY;
int tmpX, tmpY;
 
int result = 0;
 
int main()
{
    int flag = 0;
    input();
    int tmp = mapCheck();
    if (tmp == 0) {
        flag++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1 && visit[i][j] == 0) {
             
                q[rear][0] = i;
                q[rear][1] = j;
                rear++;
                visit[i][j] = 1;
            }
        }
    }
 
    while (front <rear) {
 
        currentY = q[front][0];
        currentX = q[front][1];
        front++;
 
        for (int k = 0; k < 4; k++) {
            tmpY = currentY + dirY[k];
            tmpX = currentX + dirX[k];
            if (check(tmpY, tmpX) == 1 && map[tmpY][tmpX] == 0) {
                q[rear][0] = tmpY;
                q[rear][1] = tmpX;
                rear++;
                visit[tmpY][tmpX] = visit[currentY][currentX] + 1;
            }
        }
 
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    */
    if (flag == 1) {
        printf("0");
    }
    else if (flag == 0 ) {
        result = maxVisit();
        printf("%d", result-1);
     
    }
 
}
 
int maxVisit()
{
 
    int max=0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visit[i][j] == 0 && map[i][j] ==0) {
                return 0;
            }
            if (max < visit[i][j]) {
                max = visit[i][j];
            }
        }
    }
    return max;
 
}
 
int mapCheck() {//하나라도 안익어 있으면 1;
                //모두 익어있으면 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                return 1;
            }
        }
    }
 
    return 0;
}
 
int check(int y, int x) {
 
    if (y >= 0 && y < n&&x >= 0 && x < m && visit[y][x] == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
void input()
{
    scanf("%d %d", &m, &n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}
 
/*
 
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
 
--> 8
 
6 4
1 1 1 1 1 1 
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
 
6 4
1 1 1 1 1 1
1 1 -1 1 1 1
1 -1 0 -1 1 1
1 1 -1 1 1 1
 
*/
