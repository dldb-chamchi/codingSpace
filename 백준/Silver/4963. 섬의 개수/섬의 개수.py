#백준 4963, 섬의 개수

from collections import deque

def bfs(i, j, grid):
    dx = [-1, 1, 0, 0, -1, 1, 1, -1]
    dy = [0, 0, 1, -1, 1, -1, 1, -1]

    Q = deque(); Q.append((i, j))
    while Q:
        x, y = Q.popleft()
        for k in range(8):
            nx, ny = x + dx[k], y + dy[k]
            if nx >= H or ny >= W or nx < 0 or ny < 0:
                continue
            if not grid[nx][ny]:
                continue
            grid[nx][ny] = 0
            Q.append((nx, ny))

while True:
    cnt = 0
    W, H = map(int, input().split())
    if not (W and H):
        break
    grid = [list(map(int, input().split())) for _ in range(H)]
    
    for i in range(H):
        for j in range(W):
            if grid[i][j] == 1:
                grid[i][j] = 0
                bfs(i, j, grid)
                cnt += 1

    print(cnt)

