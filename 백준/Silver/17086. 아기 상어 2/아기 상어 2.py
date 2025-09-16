import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0, -1, -1, 1, 1]
dy = [0, 0, -1, 1, 1, -1, 1, -1]

N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]

dist = [[-1] * M for _ in range(N)]
q = deque()

for i in range(N):
    for j in range(M):
        if grid[i][j] == 1:
            dist[i][j] = 0
            q.append((i, j))

while q:
    x, y = q.popleft()
    for k in range(8):
        nx, ny = x + dx[k], y + dy[k]
        if 0 <= nx < N and 0 <= ny < M and dist[nx][ny] == -1:
            dist[nx][ny] = dist[x][y] + 1
            q.append((nx, ny))

ans = 0
for i in range(N):
    for j in range(M):
        ans = max(ans, dist[i][j])

print(ans)
