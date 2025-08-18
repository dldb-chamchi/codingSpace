#백준, 14430 자원 캐기

N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

dp = [[0]*(M+1) for _ in range(N+1)]

for i in range(N):
    for j in range(M):
        dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1])

print(max(map(max, dp)))