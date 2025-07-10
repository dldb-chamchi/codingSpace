#백준, 1158 요세푸스 문제

from collections import deque

N, K = map(int, input().split())

q = deque()
answer = []

for i in range(1, N+1):
    q.append(i)

i = 1
print("<", end="")
while True:
    if len(q) == 1:
        break
    if i % K == 0:
        print(q.popleft(), end=", ")
        i += 1
    else:
        num = q.popleft()
        q.append(num)
        i += 1

print(q.popleft(), end = "")
print(">")
