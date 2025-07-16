#백준, 1652 누울 자리를 찾아라

import sys
input = sys.stdin.readline

N = int(input().rstrip())
room = [list(input().rstrip()) for _ in range(N)]


rowCnt = 0
for i in range(N):
    dotCnt = 0
    xCnt = 0
    for j in range(N):
        if room[i][j] == '.':
            dotCnt += 1
        else:
            if dotCnt >= 2:
                rowCnt += 1
            dotCnt = 0

    if dotCnt >= 2:
        rowCnt += 1

colCnt = 0
for i in range(N):
    dotCnt = 0
    for j in range(N):
        if room[j][i] == '.':
                dotCnt += 1
        else:
            if dotCnt >= 2:
                colCnt += 1
            dotCnt = 0
    if dotCnt >= 2:
        colCnt += 1

print(rowCnt, colCnt)