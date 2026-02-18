N, K = map(int, input().split())

coins = []

dp = [0]*(K+1)

for i in range(N):
  coins.append(int(input()))

dp[0] = 1

for i in range(1, N+1):
  for j in range(coins[i-1], K+1):
      dp[j] += dp[j-coins[i-1]]

print(dp[K])
