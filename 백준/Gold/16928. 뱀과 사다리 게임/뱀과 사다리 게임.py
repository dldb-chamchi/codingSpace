from collections import deque

def bfs():
  while Q:
    x = Q.popleft()
    for i in range(1, 7):
      nx = x + i
      if nx > 100:
        continue
      if nx in ladderSnake:
        nx = ladderSnake[nx]
      if dist[nx] != -1:
        continue
      
      dist[nx] = dist[x]+1
      if nx == 100:
        print(dist[100])
        return
      Q.append(nx)

N, M = map(int, input().split())

ladderSnake = {}
dist = [-1]*101

Q = deque()
Q.append(1)
dist[1] = 0
for _ in range(N):
  x, y = map(int, input().split())
  ladderSnake[x] = y

for _ in range(M):
  u, v = map(int, input().split())
  ladderSnake[u] = v

bfs()