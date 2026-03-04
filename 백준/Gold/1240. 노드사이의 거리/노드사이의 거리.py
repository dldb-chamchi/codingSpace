def dfs(visit, node, target, s):
  if node == target:
    return s
  
  for n, dist in tree[node]:
    if visit[n]:
      continue
    visit[n] = True
    result = dfs(visit, n, target, s+dist)
    if result is not None:
      return result

N, M = map(int, input().split())

tree = [[] for _ in range(N+1)]

for _ in range(N-1):
  a, b, d = map(int, input().split())
  tree[a].append((b, d))
  tree[b].append((a, d))

for _ in range(M):
  a, b = map(int, input().split())
  visit = [False]*(N+1)
  visit[a] = True
  print(dfs(visit, a, b, 0))