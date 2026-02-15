N, M = map(int, input().split())



grid = [list(map(int, input().split())) for _ in range(N)]

home = []
chicken = []

for i in range(N):
  for j in range(N):
    if grid[i][j] == 1:
      home.append([i, j])
    elif grid[i][j] == 2:
      chicken.append([i, j])

visit = [False]*(len(chicken))

ans = 9999999
def back(start, depth):
  global ans
  if depth == M:
    tmp = 0
    for h in home:
      dist = 9999999
      for i in range(len(chicken)):
        if visit[i]:
          d = abs(chicken[i][0]-h[0])+abs(chicken[i][1]-h[1])
          dist = min(dist, d)
      tmp += dist
    
    ans = min(ans, tmp)
    return
  
  for i in range(start, len(chicken)):
    if visit[i]: continue

    visit[i] = True
    back(i+1, depth+1)
    visit[i] = False

back(0, 0)

print(ans)