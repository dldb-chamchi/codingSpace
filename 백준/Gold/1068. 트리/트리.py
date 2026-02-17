N = int(input())
nodes = list(map(int, input().split()))
rNode = int(input())

graph = [[] for _ in range(N)]

cnt = 0

for i in range(N):
  if nodes[i] == -1:
    root = i
  else: graph[nodes[i]].append(i)

if rNode == root:
  print(0)
  exit()

parent = nodes[rNode]
graph[parent].remove(rNode)

def dfs(node):
  global cnt

  if len(graph[node]) == 0:
    cnt += 1
    return
  
  for n in graph[node]:
    dfs(n)

dfs(root)
print(cnt)