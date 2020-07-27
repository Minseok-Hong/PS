N, M = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(N)]

print(N, M)

homeX = []
homeY = []
marketX = []
marketY = []

for x in range(N):
    for y in range(N):
        print("%d "%map[x][y],end="")
    print("")


for x in range(N):
    for y in range(N):
        map[x][y] = 1
    print("")

for x in range(N):
    for y in range(N):
        print("%d "%map[x][y],end="")
    print("")