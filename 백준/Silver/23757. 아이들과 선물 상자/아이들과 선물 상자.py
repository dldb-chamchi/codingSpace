import heapq

N, M = map(int, input().split())

box = list(map(int, input().split()))
gift = list(map(int, input().split()))

box = [-x for x in box]
heapq.heapify(box)

for g in gift:
  if not box:
    print(0)
    sys.exit()

  n = heapq.heappop(box)
  if -n >= g:
    heapq.heappush(box, n+g)
  else:
    print(0)
    exit()

print(1)