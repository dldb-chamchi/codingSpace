N, K = map(int, input().split())

dp = [999999]*(K+1)

coin = []

dp[0] = 0

for _ in range(N):
  coin.append(int(input()))

for c in coin:
  for i in range(c, K+1):
    dp[i] = min(dp[i], dp[i-c]+1)

print(dp[K] if dp[K] != 999999 else -1)