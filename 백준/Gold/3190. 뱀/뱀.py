#백준, 3190 뱀

from collections import deque

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

N = int(input())
K = int(input())
grid = [[0]*(N+1) for i in range(N+1)]
directions = {}

for i in range(K):
    x, y = map(int, input().split())
    grid[x][y] = 2

L = int(input())

for i in range(L):
    X, C = input().split()
    directions[int(X)] = C

x, y = 1, 1
cnt = 0
direc = 0
grid[1][1] = 1
Q = deque()
Q.append((1, 1))

def turnDirection(direc, C):
    if C == 'L':
        return (direc - 1) % 4
    else:
        return (direc + 1) % 4

while True:
    cnt += 1
    x += dx[direc]
    y += dy[direc]

    if x > N or y > N or x <= 0 or y <= 0:
        break
    if grid[x][y] == 1:
        break
    elif grid[x][y] == 0:
        bx, by = Q.popleft()
        grid[bx][by] = 0
    
    grid[x][y] = 1
    Q.append((x, y))
    if cnt in directions:
        direc = turnDirection(direc, directions[cnt])

print(cnt)
        
