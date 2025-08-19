#백준 15486 퇴사 2

import sys
input = sys.stdin.readline

N = int(input())

schedule = []
dp = [0]*(N+1)

for i in range(N):
    schedule.append(list(map(int, input().split())))

maxP = 0
for i in range(N):
    t, p = schedule[i][0], schedule[i][1]
    maxP = max(maxP, dp[i])
    if i + t > N:
        continue
    dp[i+t] = max(maxP+p, dp[i+t])

print(max(dp))