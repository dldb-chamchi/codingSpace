#백준, 2491 수열

import sys
input = sys.stdin.readline

N = int(input())
sequence = list(map(int, input().rstrip().split()))

cnt1 = 1
maxCnt = 1
for i in range(len(sequence)-1):
    if sequence[i] <= sequence[i+1]:
        cnt1 += 1
    else:
        maxCnt = max(maxCnt, cnt1)
        cnt1 = 1

maxCnt = max(maxCnt, cnt1)    

cnt2 = 1
for i in range(len(sequence)-1, 0, -1):
    if sequence[i] <= sequence[i-1]:
        cnt2 += 1
    else:
        maxCnt = max(maxCnt, cnt2)
        cnt2 = 1

print(max(maxCnt, cnt2))