# 백준 1913 달팽이
N = int(input().strip())
num = int(input().strip())

grid = [[0]*N for _ in range(N)]

x = y = N // 2
grid[x][y] = 1

nowNum = 1
repeat = 1
d = 0

dx = [-1, 0, 1, 0]  # 위, 오른, 아래, 왼
dy = [0, 1, 0, -1]

ax, ay = (x+1, y+1) if num == 1 else (0, 0)

while nowNum < N * N:
    for _ in range(2):
        nx, ny = dx[d % 4], dy[d % 4]
        for _ in range(repeat):
            if nowNum >= N * N:
                break
            x += nx
            y += ny
            nowNum += 1
            grid[x][y] = nowNum
            if nowNum == num:
                ax, ay = x + 1, y + 1
        d += 1
    repeat += 1

for row in grid:
    print(*row)

print(ax, ay)
