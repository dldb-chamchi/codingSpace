#백준 16918, 봄버맨

import sys
input = sys.stdin.readline

R, C, N = map(int, input().rstrip().split())

grid = [list(input().rstrip()) for _ in range(R)]
time = [[0]*C for _ in range(R)]

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def boomSet():
    for i in range(R):
        for j in range(C):
            if grid[i][j] == '.':
                grid[i][j] = 'O'
                time[i][j] = t

def boom():
    boomList = []
    for i in range(R):
        for j in range(C):
            if grid[i][j] == 'O' and time[i][j] == t-3:
                boomList.append((i, j))

    for x, y in boomList:
        grid[x][y] = '.'
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx >= R or ny >= C or nx < 0 or ny < 0:
                continue
            
            grid[nx][ny] = '.'

t = 1
while t < N:
    t += 1
    if t % 2 == 0:
        boomSet()
    else:
        boom()

for row in grid:
    print(''.join(row))