#백준, 3151 합이 0

import sys
input = sys.stdin.readline

N = int(input().rstrip())
coding = list(map(int, input().rstrip().split()))

cnt = 0
coding.sort()

def binarySearch(start, k):
    left, right = start, N-1
    lowerBound = N
    while left <= right:
        mid = (left + right)//2
        if coding[mid] >= k:
            lowerBound = mid
            right = mid - 1
        else:
            left = mid + 1

    left, right = start, N - 1
    upperBound = N
    while left <= right:
        mid = (left + right)//2
        if coding[mid] > k:
            upperBound = mid
            right = mid - 1
        else:
            left = mid + 1

    dupliacte = upperBound-lowerBound
    
    return dupliacte if dupliacte > 0 else 0

for i in range(N-2):
    for j in range(i+1, N-1):
        sums = coding[i] + coding[j]
        cnt += binarySearch(j+1, -sums)

print(cnt)