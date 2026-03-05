from collections import deque

N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

dist = [[-1]*M for _ in range(N)]

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

Q = deque()

for i in range(N):
  for j in range(M):
    if grid[i][j] == 2:
      Q.append((i, j))
      dist[i][j] = 0

while Q:
  x, y = Q.popleft()

  for i in range(4):
    nx, ny = x+dx[i], y+dy[i]
    if nx >= N or ny >= M or nx < 0 or ny < 0:
      continue
    if dist[nx][ny] != -1 or grid[nx][ny] == 0:
      continue
    Q.append((nx, ny))
    dist[nx][ny] = dist[x][y] + 1

for i in range(N):
  for j in range(M):
    if grid[i][j] == 0:
      dist[i][j] = 0

for row in dist:
  print(*row)