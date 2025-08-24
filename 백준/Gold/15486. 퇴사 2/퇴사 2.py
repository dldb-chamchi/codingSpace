#백준 15486 퇴사 2
'''
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
    maxP = max(maxP, dp[i]) #dp[i+1] = max(dp[i], dp[i+1])
    if i + t > N:
        continue
    dp[i+t] = max(maxP+p, dp[i+t]) #dp[i+t] = max(dp[i+t], dp[i]+p)

print(dp)
print(max(dp))
'''

import sys

input = sys.stdin.readline

n = int(input())
dp = [0 for _ in range(n+1)]

for i in range(n):
  t, p = map(int, input().split())

  #dp[i]: i번째 날의 최대수익
  dp[i] = max(dp[i], dp[i-1])
  if (i+t < n+1):
    dp[i+t] = max(dp[i+t], dp[i]+p)


print(max(dp))
