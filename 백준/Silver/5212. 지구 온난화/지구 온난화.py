#백준, 5212 지구 온난화

import sys
import copy
input = sys.stdin.readline

def bfs(x, y):
    cnt = 0
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    for i in range(4):
        nx = dx[i] + x
        ny = dy[i] + y

        if nx < 0 or nx >= R or ny < 0 or ny >= C:
            cnt += 1
            continue
        elif grid[nx][ny] == '.':
            cnt += 1

    if cnt >= 3:
        deepGrid[x][y] = '.'

R, C = map(int, input().rstrip().split())

grid = [list(input().rstrip()) for _ in range(R)]

deepGrid = copy.deepcopy(grid)

for i in range(R):
    for j in range(C):
        if grid[i][j] == 'X':
            bfs(i, j)

minX = 20
maxX = 0
minY = 20
maxY = 0 
for i in range(R):
    for j in range(C):
        if deepGrid[i][j] == 'X':
            minX = min(minX, i)
            minY = min(minY, j)
            maxX = max(maxX, i)
            maxY = max(maxY, j)

for i in range(minX, maxX+1):
    for j in range(minY, maxY+1):
        print(deepGrid[i][j], end='')
    print()

