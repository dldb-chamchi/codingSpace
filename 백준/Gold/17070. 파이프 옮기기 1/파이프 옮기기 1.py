N = int(input())

grid = [list(map(int, input().split())) for _ in range(N)]
dp = [[[0]*3 for _ in range(N)] for _ in range(N)]
# [0] = 가로, [1] = 세로, [2] = 대각선

# 가로 설정
dp[0][1][0] = 1
for i in range(2, N):
  if grid[0][i] == 0:
    dp[0][i][0] = dp[0][i-1][0]
  else:
    break

for i in range(1, N):
  for j in range(1, N):
    if grid[i][j]:
      continue
    
    dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2] #가로 = 가로 + 대각선
    dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2] #세로 = 세로+대각선
    
    if not grid[i][j-1] and not grid[i-1][j]: 
      dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2] #대각선 = 가로+세로+대각선

print(sum(dp[N-1][N-1]))