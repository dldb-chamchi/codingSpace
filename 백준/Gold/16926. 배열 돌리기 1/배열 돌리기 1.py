N, M, R = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

for _ in range(R):
    for i in range(min(N, M)//2):
        tmp = grid[i][i]
        #top
        for j in range(i, M-i-1):
            grid[i][j] = grid[i][j+1]
                    
        #right
        for j in range(i, N-i-1):
            grid[j][M-i-1] = grid[j+1][M-i-1]

        #bottom
        for j in range(M-i-1, i, -1):
            grid[N-i-1][j] = grid[N-i-1][j-1]

        #left
        for j in range(N-i-1, i, -1):
            grid[j][i] = grid[j-1][i]

        grid[i+1][i] = tmp
        
for row in grid:
    print(*row)
            