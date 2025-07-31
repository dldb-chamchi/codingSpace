def recur(n, k):
    if k == 0: return 0
    if k == 1: return 1

    if dp[n][k]: return dp[n][k]

    res = 0
    for i in range(n+1):
        res += recur(i, k-1)%1000000000
    dp[n][k] = res%1000000000

    return dp[n][k]

N, K = map(int, input().split())

dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

print(recur(N, K))