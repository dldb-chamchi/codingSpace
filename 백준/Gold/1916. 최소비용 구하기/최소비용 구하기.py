import sys
import heapq

input = sys.stdin.readline

INF = 10**18

N = int(input())
M = int(input())

graph = [[] for _ in range(N+1)]
dist = [INF]*(N+1)

for _ in range(M):
  a, b, c = map(int, input().split())
  graph[a].append([b, c])

start, end = map(int, input().split())

def dijkstra(s):
  pq = [] #리스트를 힙으로 쓰기 위해
  dist[s] = 0
  heapq.heappush(pq, (0, s))

  while pq:
    cost, node = heapq.heappop(pq) #힙에 남아있는 값중에서 비용 가장 작은

    if dist[node] < cost: #이미 알고 있는 길이 더 비용 작음
      continue

    for n, c in graph[node]: #다음 노드로 가는 길
      ncost = c+cost #다음 노드로 가는 비용

      if ncost < dist[n]: #다음 노드로 가는 현재 계산 비용이 알고 있는 다음 노드로 가는 비용보다 작다면
        dist[n] = ncost #갱신
        heapq.heappush(pq, (ncost, n))

dijkstra(start)
print(dist[end])
