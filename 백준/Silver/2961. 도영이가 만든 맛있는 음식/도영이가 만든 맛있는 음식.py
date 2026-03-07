def back(depth, n, start, visit):
  global ans
  if depth == n:
    S, B = 1, 0
    for i in range(N):
      if visit[i]:
        S *= ingre[i][0]
        B += ingre[i][1]
    ans = min(ans, abs(S-B))
    return
  for i in range(start, N):
    if visit[i]:
      continue
    visit[i] = True
    back(depth+1, n, i+1, visit)
    visit[i] = False

N = int(input())

ingre = [list(map(int, input().split())) for _ in range(N)]
ans = int(1e9)

for i in range(1, N+1):
  visit = [False]*(N)
  back(0, i, 0, visit)
print(ans)