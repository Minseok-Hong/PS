/**************************************************************
    Problem: 1370
    User: hong4243
    Language: C
    Result: Success
    Time:1 ms
    Memory:2264 kb
****************************************************************/
 
 
#include <stdio.h>
#pragma warning(disable:4996)
 
int n;
int confer[100001][3];
int start = 0;
int end;
int tmpEnd;
int count = 0;
int max = 0;
int tmpFlag = 0;
int flag = 0;
 
int result[501];
int resultIndex=0;
 
int main()
{
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &confer[i][0], &confer[i][1], &confer[i][2]);
    }
    end = confer[0][2];
 
    for (int i = 0; i < n; i++) {
        if (confer[i][2] < end) {
            end = confer[i][2];
            result[resultIndex] = confer[i][0];
        }
    }
    resultIndex++;
    start = end;
    count++;
 
    while (1) {
        for (int i = 0; i < n; i++) {
            if (end > confer[i][1]) {
                flag++;
            }
        }
        if (flag == n) {
            break;
        }
        flag = 0;
 
        for (int i = 0; i < n; i++) {
            if (confer[i][1] == start && confer[i][2] == start) {
                result[resultIndex] = confer[i][0];
                resultIndex++;
                count++;
            }
        }
 
        for (int i = 0; i < n; i++) {
            if (confer[i][1] >= start) {
                if (tmpFlag == 0) {
                    end = confer[i][2];
                    tmpFlag++;
                    flag++;
                }
                if (confer[i][2] <= end) {
                    end = confer[i][2];
                    result[resultIndex] = confer[i][0];
                    flag++;
                }
 
            }
        }
        if (flag > 0) {
            start = end;
            resultIndex++;
            count++;
        }
 
        flag = 0;
        tmpFlag = 0;
    }
 
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
}
 
/*
11
1 4
3 5
0 6
6 10
8 11
8 12
2 13
12 14
5 7
3 8
5 9
 
6
1 10
5 6
13 15
14 17
8 14
3 12
 
 
6
1 1 10
2 5 6
3 13 15
4 14 17
5 8 14
6 3 12
*/
