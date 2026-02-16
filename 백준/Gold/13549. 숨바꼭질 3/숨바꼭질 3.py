from collections import deque
import sys

N, K = map(int, sys.stdin.readline().split())

MAX = 100000
dist = [-1] * (MAX + 1)
dq = deque()

dist[N] = 0
dq.append(N)

while dq:
    x = dq.popleft()

    if x == K:
        print(dist[x])
        break

    # 0초 이동: 순간이동
    nx = x * 2
    if 0 <= nx <= MAX and dist[nx] == -1:
        dist[nx] = dist[x]
        dq.appendleft(nx)

    # 1초 이동: -1
    nx = x - 1
    if 0 <= nx <= MAX and dist[nx] == -1:
        dist[nx] = dist[x] + 1
        dq.append(nx)

    # 1초 이동: +1
    nx = x + 1
    if 0 <= nx <= MAX and dist[nx] == -1:
        dist[nx] = dist[x] + 1
        dq.append(nx)