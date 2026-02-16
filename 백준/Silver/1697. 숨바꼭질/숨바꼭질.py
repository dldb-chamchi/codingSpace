from collections import deque

N, K = map(int, input().split())

MAX = 100001

dist = [0]*MAX

Q = deque()

Q.append(N)
dist[N]=1

def bfs():
  
  while Q:
    n = Q.popleft()

    if n == K:
      return dist[K]
    
    if n < K and dist[n+1] == 0:
      dist[n+1] = dist[n]+1
      Q.append(n+1)
    if n > 0 and dist[n-1] == 0:
      dist[n-1] = dist[n]+1
      Q.append(n-1)
    if 2*n < MAX and dist[2*n] == 0:
      dist[2*n] = dist[n]+1
      Q.append(2*n)
  
print(bfs()-1)
