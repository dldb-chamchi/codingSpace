#백준, 12887 경로게임

import sys
input = sys.stdin.readline

def bfs(x, y):
    cnt = 1
    nx = x; ny = y
    while ny != M-1:
        if grid[nx][ny+1] == '.':
            ny += 1
        else:
            nx = 0 if nx == 1 else 1
        cnt += 1
    return cnt

M = int(input())
grid = [list(input().rstrip()) for i in range(2)]

white = sum(row.count('.') for row in grid)

cnt1 = 9999; cnt2 = 9999
if grid[0][0] == '.':
    cnt1 = bfs(0, 0)
if grid[1][0] == '.':
    cnt2 = bfs(1, 0)

print(white-min(cnt1, cnt2))
