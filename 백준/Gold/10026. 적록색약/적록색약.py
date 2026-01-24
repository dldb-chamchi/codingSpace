from collections import deque

def bfs():
  Q = deque()
  num = 0

  for i in range(N):
    for j in range(N):
      if not visit[i][j]:
        Q.append((i, j))
        visit[i][j] = True
        num += 1
      while Q:
        x, y = Q.popleft()
        for k in range(4):
          nx, ny = x + dx[k], y + dy[k]
          if nx >= N or ny >= N or nx < 0 or ny < 0:
            continue
          if visit[nx][ny] or grid[nx][ny] != grid[x][y]:
            continue
          visit[nx][ny] = True
          Q.append((nx, ny))
  return num

def abBfs():
  Q = deque()
  num = 0

  for i in range(N):
    for j in range(N):
      if not abVisit[i][j]:
        Q.append((i, j))
        abVisit[i][j] = True
        num += 1
      while Q:
        x, y = Q.popleft()
        for k in range(4):
          nx, ny = x + dx[k], y + dy[k]
          if nx >= N or ny >= N or nx < 0 or ny < 0:
            continue
          if abVisit[nx][ny] or grid[nx][ny] != grid[x][y]:
            continue
          abVisit[nx][ny] = True
          Q.append((nx, ny))
  return num

N = int(input())
visit = [[False]*N for _ in range(N)]
abVisit = [[False]*N for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

grid = [list(input()) for _ in range(N)]

print(bfs(), end = ' ')

for i in range(N):
  for j in range(N):
    if grid[i][j] == 'G':
      grid[i][j] = 'R'

print(abBfs())
