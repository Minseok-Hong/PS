nclude <stdio.h>
#pragma warning(disable:4996)
 
void input();
 
int n;
int map[13][13];
int visit[13] = { 0 };
int result=1000000;
 
void dfs(int src, int des, int sum, int count) {
 
     
     
    /*
    printf("%d -> %d : sum(%d + %d)=%d count(%d)\n", src, des, sum, map[src][des], sum + map[src][des], count);
 
    printf("  0  1  2  3  4   \n");
    for (int i = 0; i < n; i++) {
        printf("%3d", visit[i]);
    }
    printf("\n===============\n");
    */
    if (count == n-1 && map[des][0] != 0) {
        visit[des] = 1;
        //printf("%d -> 0 : sum(%d + %d)=%d count(5)\n", des, sum + map[src][des], map[des][0], sum + map[src][des] + map[des][0]);
        sum = sum + map[src][des] + map[des][0];
        if (sum < result) {
            result = sum;
        }
        visit[des] = 0;
        return;
    }
    visit[des] = 1;
    for (int i = 1; i < n; i++) {
        if (visit[i] == 0 && map[des][i] != 0) {
            dfs(des, i, sum + map[src][des], count + 1);
             
        }
         
    }
    visit[des] = 0;
 
}
int main()
{
    input();
 
    for (int i = 1; i < n; i++) {
        if (map[0][i] != 0) {
         
            dfs(0, i, 0, 1);
        }
         
    }
 
 
    printf("%d", result);
 
}
void input()
{
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
 
}
 
/*
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
 
-->30
 
 
3
0 86 0
69 0 83
45 97 0
 
-->214
 
 
 
6
0 93 23 32 39 46
0 0 7 58 59 13
40 98 0 14 33 98
3 39 0 0 13 16
51 25 19 88 0 47
65 81 63 0 6 0
 
--> 101
*/
