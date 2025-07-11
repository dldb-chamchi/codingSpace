import sys
input = sys.stdin.readline

from itertools import permutations

N = int(input())
nums = list(map(int, input().split()))
sequence = list(permutations(nums, N))

ans = 0
for i in sequence:
    sum = 0
    for j in range(N-1):
        sum += abs(i[j]-i[j+1])
    ans = max(ans, sum)

print(ans)

