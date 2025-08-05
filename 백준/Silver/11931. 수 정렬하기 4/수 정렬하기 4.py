#백준 11931, 수 정렬 4

import sys
input = sys.stdin.readline

N = int(input().rstrip())
nums = []

for i in range(N):
    nums.append(int(input().rstrip()))
    
nums.sort(reverse=True)

for n in nums:
    print(n)
