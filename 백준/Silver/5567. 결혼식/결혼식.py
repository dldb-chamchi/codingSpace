N = int(input())
M = int(input())

graph = [[] for _ in range(N+1)]

for i in range(M):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

friends = set(graph[1])
oneF = graph[1]

for i in oneF:
  for j in graph[i]:
    friends.add(j)

if 1 in friends:
  print(len(friends)-1)
else:
  print(len(friends))