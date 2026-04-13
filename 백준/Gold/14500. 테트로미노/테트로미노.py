N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

tetris = [[(0,1), (0,2), (0,3)], [(1,0), (2,0), (3,0)],
        [(0,1), (1,0), (1,1)],
        [(1,0),(1,1),(2,1)], [(0,-1), (1,-1), (1,-2)],
        [(1,0), (1,-1), (2,-1)],[(0,1), (1,1), (1,2)],
        [(1,0), (2,0), (2,1)], [(0,1), (0,2), (1,0)],
        [(0,1),(1,1), (2,1)], [(0,1), (0,2), (-1,2)],
        [(1,0),(2,0),(2,-1)],[(0,1),(0,2),(1,2)],
        [(1,0),(2,0),(0,1)], [(1,0),(1,1),(1,2)],
        [(1,0),(1,1),(1,-1)], [(1,0),(1,1),(2,0)],
        [(0,-1),(1,0),(0,1)],[(0,1),(-1,1),(1,1)] 
]

def solve(i, j, tetro):
  val = grid[i][j]

  for x, y in tetro:
    nx, ny = i+x, j+y
    if nx < 0 or nx >= N or ny < 0 or ny >= M:
      return 0
    else:
      val += grid[nx][ny]
  
  return val

ans = 0
for i in range(N):
  for j in range(M):
    for tetro in tetris:
      ans = max(ans, solve(i, j, tetro))

print(ans)