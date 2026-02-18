for _ in range(int(input())):
  N = int(input())
  coins = list(map(int, input().split()))
  K = int(input())

  dp = [[0]*(K+1) for _ in range(N+1)]

  for i in range(N+1):
    dp[i][0] = 1

  for i in range(1, N+1):
    for j in range(1, K+1):
      dp[i][j] = dp[i-1][j]
      if j-coins[i-1] >= 0:
        dp[i][j] += dp[i][j-coins[i-1]]

  print(dp[N][K])
