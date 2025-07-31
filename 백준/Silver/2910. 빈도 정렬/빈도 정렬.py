#백준, 2910 빈도 정렬

import sys
input = sys.stdin.readline

N, C = map(int, input().rstrip().split())

seq = list(map(int, input().rstrip().split()))

freq = {}

for n in seq:
    if n in freq:
        freq[n] += 1
    else:
        freq[n] = 1

sortedFreq = sorted(freq.items(), key = lambda x: x[1], reverse=True)

for num, cnt in sortedFreq:
    print(" ".join([str(num)] * cnt), end = " ")