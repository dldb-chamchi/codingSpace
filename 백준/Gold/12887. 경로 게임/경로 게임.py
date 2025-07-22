#백준, 12887 경로게임

import sys
input = sys.stdin.readline

MAX = 9999

def bfs(x, y):
    cnt = 1
    if grid[x][y] != '.':
        return MAX
    while y != M-1:
        if grid[x][y+1] == '.':
            y += 1
        else:
            x = 0 if x == 1 else 1
        cnt += 1
    return cnt

M = int(input())
grid = [list(input().rstrip()) for i in range(2)]

white = sum(row.count('.') for row in grid)

print(white-min(bfs(0, 0), bfs(1, 0)))
