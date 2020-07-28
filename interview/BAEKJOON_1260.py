def dfs(v):
    print(v,end=" ")
    visit[v] = 1
    for i in range(1, n+1):
        if visit[i] == 0 and matrix[v][i] == 1:
            dfs(i)
def bfs(v):
    queue = [v]
    visit[v] = 1
    while(queue):
        v = queue[0]
        print(v, end=' ')
        del queue[0]
        for i in range(1, n+1):
            if visit[i] == 0 and matrix[v][i] == 1:
                queue.append(i)
                visit[i] = 1


n, m, v = map(int, input().split())
visit = [0 for i in range(n+1)]
matrix = [[0] * (n + 1) for i in range(n + 1)]
for i in range(m):
    x,y = map(int,input().split())
    matrix[x][y] = 1
    matrix[y][x] = 1

dfs(v)
print()
visit = [0 for i in range(n+1)]
bfs(v)