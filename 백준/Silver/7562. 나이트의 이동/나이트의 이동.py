from collections import deque

T = int(input())

dx = [2, 2, -2, -2, 1, -1, -1, 1]
dy = [1, -1, 1, -1, 2, -2, 2, -2]

def bfs(dist, X, Y):
  Q = deque()
  Q.append((X, Y))
  dist[X][Y] = 1

  while Q:
    x, y = Q.popleft()
    for i in range(8):
      nx, ny = dx[i] + x, y + dy[i]

      if nx >= L or ny >= L or nx < 0 or ny < 0 :
        continue
      if dist[nx][ny] != 0:
        continue
      dist[nx][ny] = dist[x][y] + 1
      Q.append((nx, ny))
      

for _ in range(T):
  L = int(input())
  X, Y = map(int, input().split())
  DX, DY = map(int, input().split())
  dist = [[0]*L for _ in range(L)]

  bfs(dist, X, Y)
  print(dist[DX][DY] - 1)