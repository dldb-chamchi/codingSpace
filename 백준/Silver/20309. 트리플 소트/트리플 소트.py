#백준, 20309 트리플 소트

import sys
input = sys.stdin.readline

N = int(input().rstrip())

nums = list(map(int, input().split()))

for i in range(N):
    if i%2 and nums[i]%2:
        print("NO")
        exit()

print("YES")