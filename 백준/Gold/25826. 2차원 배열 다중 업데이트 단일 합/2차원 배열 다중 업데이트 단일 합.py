N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]
update = [[0]*(N+1) for _ in range(N+1)]

for _ in range(M):
  op = list(map(int, input().split()))

  if op[0] == 1:
    x, y, a, b, d = op[1], op[2], op[3], op[4], op[5]

    update[x][y] += d
    update[x][b+1] -= d
    update[a+1][y] -= d
    update[a+1][b+1] += d

  else:
    x, y, a, b= op[1], op[2], op[3], op[4]
    
    for i in range(N):
      for j in range(1, N):
        update[i][j] += update[i][j-1]

    for i in range(N):
      for j in range(1, N):
        update[j][i] += update[j-1][i]

    sums = 0
    for i in range(x, a+1):
      for j in range(y, b+1):
        sums += grid[i][j] + update[i][j]

    print(sums)