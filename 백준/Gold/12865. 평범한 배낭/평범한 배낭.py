N, K = map(int, input().split())

dp = [[0]*(K+1) for _ in range(N+1)]

W = [0]
V = [0]

for _ in range(N):
  w, v = map(int, input().split())
  W.append(w); V.append(v)

for i in range(1, K+1):
  for j in range(1, N+1):
    if i >= W[j]:
      dp[j][i] = max(dp[j-1][i], dp[j-1][i-W[j]]+V[j])
    else:
      dp[j][i] = dp[j-1][i]

print(dp[N][K])