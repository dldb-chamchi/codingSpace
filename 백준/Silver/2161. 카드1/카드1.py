from collections import deque

Q = deque()

N = int(input())

for i in range(N):
    Q.append(i+1)

while Q:
    print(Q.popleft(), end = ' ')
    if Q:
        Q.append(Q.popleft())
