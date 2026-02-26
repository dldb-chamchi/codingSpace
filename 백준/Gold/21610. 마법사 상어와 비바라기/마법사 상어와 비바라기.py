N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]
cloud = [[False]*N for _ in range(N)]

direc = [[0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1]]

diago = [[-1, -1], [-1, 1], [1, 1], [1, -1]]

cloud[N-1][0] = True
cloud[N-1][1] = True
cloud[N-2][0] = True
cloud[N-2][1] = True

for _ in range(M):
  d, s = map(int, input().split())
  #이동전에 cloud False, 이동하고 마지막 위치에 cloud True하기

  newCloud = [[False]*N for _ in range(N)]
  for i in range(N):
    for j in range(N):
      if cloud[i][j]:
        nx, ny = i, j
        for _ in range(s):
          nx, ny = nx+direc[d-1][0], ny+direc[d-1][1]
          if nx >= N:
            nx = 0
          if ny >= N:
            ny = 0
          if nx < 0:
            nx = N-1
          if ny < 0:
            ny = N-1
        newCloud[nx][ny] = True

  cloud = newCloud

  for i in range(N): #비내리기
    for j in range(N):
      if cloud[i][j]:
        grid[i][j] += 1
      
  for i in range(N):
    for j in range(N):
      cnt = 0 #대각선 물 1이상
      if cloud[i][j]:
        for x, y in diago:
          nx, ny = i+x, j+y
          if nx >= N or ny >= N or nx < 0 or ny < 0:
            continue
          if grid[nx][ny] >= 1:
            cnt += 1
        grid[i][j] += cnt

  for i in range(N):
    for j in range(N):
      if cloud[i][j]:
        cloud[i][j] = False
      elif grid[i][j] >= 2:
          cloud[i][j] = True
          grid[i][j] -= 2

ans = 0
for i in range(N):
  for j in range(N):
    ans += grid[i][j]

print(ans)