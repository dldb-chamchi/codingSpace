from collections import deque
N , K = map(int,input().split())


deq = deque()
deq.append([N,0])
visited = [N]

while True:
    X = deq.popleft()
    posi = X[0]
    second = X[1]

    if posi == K:
        print(second)
        break

    if posi * 2 >= 0 and posi * 2 <= 100000 and posi * 2 not in visited:
        visited.append(posi * 2)
        deq.append([posi * 2,second])
    if posi - 1 >= 0 and posi - 1 <= 100000 and posi - 1 not in visited:
        visited.append(posi - 1)
        deq.append([posi - 1,second + 1])
    if posi + 1 >= 0 and posi + 1 <= 100000 and posi + 1 not in visited:
        visited.append(posi + 1)
        deq.append([posi + 1,second + 1])