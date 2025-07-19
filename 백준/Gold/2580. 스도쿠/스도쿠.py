#백준 2580, 스도쿠

import sys
input = sys.stdin.readline

def back(depth):
    if depth == len(zero):
        for num in grid:
            print(*num)
        exit()

    x, y = zero[depth]

    for i in range(1, 10):
        if rowCheck(x, i) and colCheck(y, i) and threeBy(x, y, i):
            grid[x][y] = i
            back(depth+1)
            grid[x][y] = 0

def rowCheck(x, n):
    return n not in grid[x]

def colCheck(y, n):
    for i in range(9):
        if n == grid[i][y]:
            return False
    return True

def threeBy(x, y, n):
    for i in range(3):
        for j in range(3):
            if n == grid[x//3 * 3 + i][y//3 * 3 + j]:
                return False
    return True

grid = [list(map(int, input().rstrip().split())) for _ in range(9)]
zero = []

for i in range(9):
    for j in range(9):
        if grid[i][j] == 0:
            zero.append([i, j])

back(0)