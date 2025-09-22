N = int(input())

grid = [list(input()) for _ in range(N)]

maxCnt = 1

def checkRowMax():
    best = 1
    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if grid[i][j] == grid[i][j+1]:
                cnt += 1
            else:
                cnt = 1
            best = max(best, cnt)
    return best

def checkColMax():
    best = 1
    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if grid[j][i] == grid[j+1][i]:
                cnt += 1
            else:
                cnt = 1
            best = max(best, cnt)
    return best

for i in range(N):
    for j in range(N-1):
        grid[i][j], grid[i][j+1] = grid[i][j+1], grid[i][j]
        maxCnt = max(maxCnt, checkRowMax(), checkColMax())
        grid[i][j], grid[i][j+1] = grid[i][j+1], grid[i][j]

        grid[j][i], grid[j+1][i] = grid[j+1][i], grid[j][i]
        maxCnt = max(maxCnt, checkRowMax(), checkColMax())
        grid[j][i], grid[j+1][i] = grid[j+1][i], grid[j][i]

print(maxCnt)
