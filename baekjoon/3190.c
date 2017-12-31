#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cstdio>
#include <stack>
#define MAX_SIZE 100
#define MOD 1000000009
#define ull unsigned long long
#define ll long long
#define mp make_pair
 
using namespace std;
 
typedef pair<int, int> p;
 
int N, K, L;
int map[MAX_SIZE][MAX_SIZE]; // 사과는 2, 뱀은 1, 맵은 0
vector<p> v; //sec, turn
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
//오른쪽 : 위 -> 오, 아래 -> 왼, 오 -> 아, 왼 -> 위
//왼쪽 : 위 -> 왼, 아래 -> 오른, 오 -> 위, 왼 -> 아
 
//r : 0 -> 3, 1 -> 2, 3 -> 1, 2 -> 0
//l : 0 -> 2, 1 -> 3, 3 -> 0, 2 -> 1
 
int turn(int now, int next)
{
    if(next == 0) // 왼쪽
    {
        if(now == 0 || now == 1) return (now + 2) % 4;
        else return 3 - now;
    }
    else // 오른쪽
    {
        if(now == 0 || now == 1) return 3 - now;
        else return (now + 2) % 4;
    }
}
 
 
void input()
{
    scanf("%d %d", &N, &K);
 
    for(int i = 0; i < K; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x - 1][y - 1] = 2;
    }
 
    scanf("%d", &L);
 
    for(int i = 0; i < L; i++)
    {
        int s;
        char c;
 
        scanf("%d %c", &s, &c);
 
        int d;
        if(c == 'L') d = 0; //왼
        else d = 1; //오른쪽
 
        v.push_back(mp(s, d));
    }
}
 
void process()
{
    vector<p> snake;
 
    int x = 0, y = 0; // 머리 위치
 
    int d = 3;
    int sec = 0;
 
    int vi = 0;//시간 벡터 인덱스
    bool v_flag = 0;//벡터가 끝나면 1이됨
 
    map[x][y] = 1;
    snake.push_back(mp(x, y));
 
    while(1)
    {
        if(!v_flag && sec == v[vi].first)
        {
            d = turn(d, v[vi++].second);
            if(vi == v.size()) v_flag = 1;
        }
 
        //다음 좌표
        int nx = x + dx[d];
        int ny = y + dy[d];
 
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) break; // 맵 벗어나는지 검사
 
        //맵검사
        if(map[nx][ny] == 1) break;
        else if(map[nx][ny] == 0)
        {
            map[snake[0].first][snake[0].second] = 0;
            snake.erase(snake.begin());
        }
 
        //스네이크 머리 갱신 및 맵 갱신
        x = nx;
        y = ny;
        map[x][y] = 1;
        snake.push_back(mp(x, y));
 
        sec++;
    }
 
    printf("%d\n", sec + 1);
}
 
 
int main()
{
    input();
    process();
 
    return 0;
}
