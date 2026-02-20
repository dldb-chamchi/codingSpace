for _ in range(int(input())):
  N, D = map(int, input().split())

  grid = [list(map(int, input().split())) for _ in range(N)]

  if D < 0:
    repeat = (-D)//45
    for _ in range(repeat):
      width = []; height = []; diagonal1 = []; diagonal2 = []
      for i in range(N):
        #가로 세로
        width.append(grid[N//2][i])
        height.append(grid[i][N//2])
        
        #대각선
        diagonal1.append(grid[i][i])
        diagonal2.append(grid[i][N-i-1])
      for i in range(N):
        grid[i][i] = height[i]
        grid[i][N-i-1] = width[N-i-1]
        grid[N//2][i] = diagonal1[i]
        grid[i][N//2] = diagonal2[i]
  else:
    repeat = D//45
    for _ in range(repeat):
      width = []; height = []; diagonal1 = []; diagonal2 = []
      for i in range(N):
        #가로 세로
        width.append(grid[N//2][i])
        height.append(grid[i][N//2])
        
        #대각선
        diagonal1.append(grid[i][i])
        diagonal2.append(grid[i][N-i-1])
      for i in range(N):
        grid[i][i] = width[i]
        grid[i][N-i-1] = height[i]
        grid[N//2][i] = diagonal2[N-i-1]
        grid[i][N//2] = diagonal1[i]
  
  for row in grid:
    print(*row)