#백준, 16401 과자 나눠주기

import sys
input = sys.stdin.readline

def binarySearch(st, end):
    if st > end:
        return end

    mid = (st+end)//2
    cnt = 0
    
    for value in snaks:
        cnt += value // mid
    
    if cnt >= M:
        return binarySearch(mid+1, end)
    else:
        return binarySearch(st, mid-1)

M, N = map(int, input().split())

snaks = list(map(int, input().split()))
snaks.sort()

print(binarySearch(1, snaks[N-1]))


