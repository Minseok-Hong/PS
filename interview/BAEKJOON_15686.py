from itertools import combinations
import sys

house = []
chicken = []
combi = []
chicken_cnt = 0
result = sys.maxsize
house_cnt = 0

N, M = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(N)]

for x in range(N):
    for y in range(N):
        if map[x][y] == 1:
            house.append((x,y))
            house_cnt += 1
        elif map[x][y] == 2:
            chicken.append((x,y))


for i in list(combinations(chicken, M)):
    combi.append(i)

for i in range(len(combi)):
    tmp_result = 0 # combi 중에 모든 집들과의 최소값
    for home_index in range(house_cnt):
        home_min = sys.maxsize
        for chickens in combi[i]:
            far = abs(chickens[0] - house[home_index][0]) + abs(chickens[1] - house[home_index][1])
            if  home_min > far:
                home_min = far
        tmp_result += home_min
    if result > tmp_result:
        result = tmp_result

print(result)

