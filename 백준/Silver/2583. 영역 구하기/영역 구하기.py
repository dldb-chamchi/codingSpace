#백준 2583, 영역 구하기

from collections import deque

def bfs(i, j):
    area = 1
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    Q = deque()
    Q.append((i, j))

    while Q:
        x, y = Q.popleft()
        for k in range(4):
            nx = dx[k] + x
            ny = dy[k] + y

            if nx >= M or ny >= N or nx < 0 or ny < 0:
                continue
            if grid[nx][ny] != 0:
                continue
            grid[nx][ny] = 2
            area += 1
            Q.append((nx, ny))
    
    areas.append(area)

M, N, K = map(int, input().split())

grid = [[0 for _ in range(N)] for _ in range(M)]
areas = []
cnt = 0
for k in range(K):
    a, b, c, d = map(int, input().split())

    for i in range(b, d):
        for j in range(a, c):
            grid[i][j] = 1
    
for i in range(M):
    for j in range(N):
        if grid[i][j] == 0:
            grid[i][j] = 2
            cnt += 1
            bfs(i, j)

areas.sort()
print(cnt)
print(*areas)