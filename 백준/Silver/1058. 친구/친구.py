#본인 친구 갯수 + depth가 2 이내인 친구들 개수 중 가장 많은 사람
from collections import deque

def bfs(num):
  cnt = 0
  Q = deque()
  Q.append(num)
  visit = [False]*(N+1)
  visit[num] = True
  while Q:
    node = Q.popleft()

    for n in graph[node]:
      if not visit[n]:
        visit[n] = True
        cnt += 1
        if node == num:
          Q.append(n)
  return cnt

N = int(input())
count = [0]*(N+1)

graph = [[] for _ in range(N+1)]
for i in range(1, N+1):
  row = input()
  for j in range(N):
    if row[j] == 'Y':
      graph[i].append(j+1)

for i in range(1, N+1):
  count[i] = bfs(i)

print(max(count))