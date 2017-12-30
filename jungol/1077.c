#include <stdio.h>
#pragma warning(disable:4996)
 
void sort();
 
int max(int a, int b);
 
int n;
int w;
int Wi[10001], Pi[10001];
int d[10001];
 
int main()
{
    scanf("%d %d", &n, &w);
 
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &Wi[i], &Pi[i]);
    }
     
    sort();
 
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j >= Wi[i]) {
                d[j] = max(d[j - Wi[i]] + Pi[i], d[j]);
             
            }
        }
    }
    printf("%d", d[w]);
 
}
void sort() {
 
    int tmp;
    int tmp2;
 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Wi[j] < Wi[j + 1]) {
                tmp = Wi[j];
                tmp2 = Pi[j];
                Wi[j] = Wi[j + 1];
                Pi[j] = Pi[j + 1];
                Wi[j + 1] = tmp;
                Pi[j + 1] = tmp2;
            }
        }
    }
}
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
 
/*
4 14
2 40
5 110
10 200
3 50
 
 
*/
 
 
 
 
 
 
 
 
 
    /*
    // i 는 보석종류
    for (int i = 1; i <= n; i++) {
        // j는 보석 무게
        for (int j = 1; j <= w; j++) {
            if (j - Wi[i]<0) {
                d[i][j] = d[i - 1][j];
            }
            else {
                d[i][j] = max(d[i][j - Wi[i]] + Pi[i], d[i - 1][j]);
            }
        }
    }
    printf("%d", d[n][w]);
 
 
}
*/
/*
4 14
2 40
5 110
10 200
3 50
*/