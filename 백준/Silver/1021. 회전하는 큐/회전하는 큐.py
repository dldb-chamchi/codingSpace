from collections import deque

N, M = map(int, input().split())

nums = list(map(int, input().split()))

d = deque()
for i in range(1, N+1):
    d.append(i)

cnt = 0
for n in nums:
    front = d[0]
    if d.index(n) <= len(d)//2:
        while d[0] != n:
            d.append(d.popleft())
            cnt += 1
    else:
        while d[0] != n:
            d.appendleft(d.pop())
            cnt += 1
    d.popleft()

print(cnt)