#백준, 17836 공주님을 구해라!

import sys
from collections import deque
input = sys.stdin.readline

N, M, T = map(int, input().rstrip().split())

grid = [list(map(int, input().split())) for _ in range(N)]

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def bfs():
    visit = [[0]*M for _ in range(N)]
    dist = [[0]*M for _ in range(N)]
    Q = deque()
    Q.append((0, 0))
    visit[0][0] = True
    while Q:
        x, y = Q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= N or ny >= M or nx < 0 or ny < 0:
                continue
            if visit[nx][ny] or grid[nx][ny] == 1:
                continue
            visit[nx][ny] = True
            dist[nx][ny] = dist[x][y] + 1
            Q.append((nx, ny))
    return dist[N-1][M-1]

def searchSword():
    visit = [[0]*M for _ in range(N)]
    dist = [[0]*M for _ in range(N)]
    Q = deque()
    Q.append((0, 0))
    visit[0][0] = True
    while Q:
        x, y = Q.popleft()
        if grid[x][y] == 2:
            return x, y, dist[x][y]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= N or ny >= M or nx < 0 or ny < 0:
                continue
            if visit[nx][ny] or grid[nx][ny] == 1:
                continue
            visit[nx][ny] = True
            dist[nx][ny] = dist[x][y] + 1
            Q.append((nx, ny))
    return 0, 0, 0

noSwordDist = bfs()
swordX, swordY, dist = searchSword()

if not noSwordDist and not dist:
    print("Fail")
elif not noSwordDist and dist:
    dist += N-swordX-1 + M-swordY-1
    if dist > T:
        print("Fail")
    else:
        print(dist)
elif noSwordDist and not dist:
    if noSwordDist > T:
        print("Fail")
    else:
        print(noSwordDist)
else:
    dist += N-swordX-1 + M-swordY-1
    value = min(noSwordDist, dist)
    if value > T:
        print("Fail")
    else:
        print(value)