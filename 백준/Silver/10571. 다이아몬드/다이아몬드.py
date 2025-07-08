#백준, 10571 다이아몬드

import sys
input = sys.stdin.readline

for _ in range(int(input().rstrip())):
    N = int(input().rstrip())
    lcs = [1 for _ in range(N)]
    wc = []
    for _ in range(N):
        wc.append(list(map(float, input().rstrip().split())))

    for i in range(N):
        for j in range(i):
            if wc[i][0] > wc[j][0] and wc[i][1] < wc[j][1]:
                lcs[i] = max(lcs[i], lcs[j]+1)
    print(max(lcs))