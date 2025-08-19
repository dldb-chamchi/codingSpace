#백준, 10703 유성

R, S = map(int, input().split())

grid = [list(input()) for _ in range(R)]

def calcDist():
    minDist = R
    for i in range(S):
        dist = -9999
        for j in range(R):
            if grid[j][i] == 'X':
                dist = j
            elif grid[j][i] == '#':
                minDist = min(minDist, j-dist-1)
                break
    return minDist

minDist = calcDist()

for i in range(R-1, -1, -1):
    for j in range(S):
        if grid[i][j] == 'X':
            grid[i+minDist][j] = grid[i][j]
            grid[i][j] = '.'

for r in range(R):
    print(''.join(grid[r]))