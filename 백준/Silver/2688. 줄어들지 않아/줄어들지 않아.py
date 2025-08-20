#백준, 2688 줄어들지 않아

import sys
input = sys.stdin.readline

T = int(input().rstrip())
dp = [[0]*10 for _ in range(65)]

for i in range(10):
    dp[1][i] = 1

for i in range(2, 65):
    for j in range(10):
        for k in range(j, 10):
            dp[i][j] += dp[i-1][k]

for _ in range(T):
    ans = 0
    n = int(input())
    for i in range(10):
        ans += dp[n][i]
    print(ans)  