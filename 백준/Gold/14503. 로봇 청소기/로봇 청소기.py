from collections import deque

N, M = map(int, input().split())
x, y, d = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]
Q = deque()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

Q.append((x, y))
cnt = 0

while Q:
  x, y = Q.popleft()
  if grid[x][y] == 0:
    cnt += 1
    grid[x][y] = 2 #청소

  clean = 0
  for i in range(4):
    nx, ny = x+dx[i], y+dy[i]
    if nx >= N or ny >= M or nx < 0 or ny < 0:
      cleant += 1
      continue
    if grid[nx][ny] != 0:
      clean += 1

  if clean == 4:
    flag = False
    if d == 0: #북
      if x+1 < N and grid[x+1][y] != 1:
        Q.append((x+1, y))
      else: flag = True
    elif d == 1:
      if y-1 >= 0 and grid[x][y-1] != 1:
        Q.append((x, y-1))
      else: flag = True
    elif d == 2:
      if x-1 >= 0 and grid[x-1][y] != 1:
        Q.append((x-1, y))
      else: flag = True
    else:
      if y+1 < M and grid[x][y+1] != 1:
        Q.append((x, y+1))
      else: flag = True
    if flag:
      print(cnt)
      exit()
  else:
    for i in range(4):
      if d == 0:
        d = 3
      else:
        d -= 1
      if d == 0:
        if x-1 >= 0 and grid[x-1][y] == 0:
          Q.append((x-1, y))
          break
      elif d == 1:
        if y+1 < M and grid[x][y+1] == 0:
          Q.append((x, y+1))
          break
      elif d == 2:
        if x+1 < N and grid[x+1][y] == 0:
          Q.append((x+1, y))
          break
      else:
        if y-1 >= 0 and grid[x][y-1] == 0:
          Q.append((x, y-1))
          break

print(cnt)