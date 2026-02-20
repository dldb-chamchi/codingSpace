import heapq

ans = 0
gorilla = {}
for i in range(int(input())):
  query = input().split()

  name = query[1]
  k = int(query[2])

  if query[0] == '1':
    if name not in gorilla:
      gorilla[name] = []
    for i in query[3:]:
      heapq.heappush(gorilla[name], -int(i))
  else:
    if name not in gorilla:
      pass
    else:
      for i in range(min(k, len(gorilla[name]))):
        ans += -heapq.heappop(gorilla[name])

print(ans)