grid = [[0]*101 for _ in range(101)]

for _ in range(4):
  x, y, a, b = map(int, input().split())

  for i in range(x, a):
    for j in range(y, b):
      grid[i][j] = 1

area = 0

for row in grid:
  area += sum(row)

print(area)
