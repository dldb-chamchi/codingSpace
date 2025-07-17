#백준, 2485 가로수

import sys
from math import gcd
input = sys.stdin.readline

N = int(input().rstrip())

tree = [int(input().rstrip()) for _ in range(N)]

diff = []

for i in range(N-1):
    diff.append(tree[i+1] - tree[i])

g = diff[0]
for i in range(1, len(diff)):
    g = gcd(g, diff[i])

cnt = 0
for i in diff:
    cnt += i//g-1

print(cnt)
