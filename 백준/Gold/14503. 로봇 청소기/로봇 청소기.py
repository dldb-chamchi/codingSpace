N, M = map(int, input().split())
x, y, d = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]

# 0:북, 1:동, 2:남, 3:서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

cnt = 0

while True:
    # 1) 현재 칸 청소
    if grid[x][y] == 0:
        grid[x][y] = 2
        cnt += 1

    # 2) 왼쪽부터 4방향 탐색
    moved = False
    for _ in range(4):
        d = (d + 3) % 4  # 왼쪽 회전
        nx, ny = x + dx[d], y + dy[d]
        if 0 <= nx < N and 0 <= ny < M and grid[nx][ny] == 0:
            x, y = nx, ny
            moved = True
            break

    if moved:
        continue

    # 3) 네 방향 모두 못 가면 뒤로 이동
    back_dir = (d + 2) % 4
    bx, by = x + dx[back_dir], y + dy[back_dir]
    if not (0 <= bx < N and 0 <= by < M) or grid[bx][by] == 1:
        break  # 뒤가 벽이면 종료
    x, y = bx, by

print(cnt)
