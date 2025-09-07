N = int(input())

dp = [0]*(N+1)

for i in range(N):
    t, p = map(int, input().split())
    dp[i] = max(dp[i], dp[i-1])
    if i + t > N:
        continue
    dp[i+t] = max(dp[i+t], dp[i]+p)


print(max(dp))