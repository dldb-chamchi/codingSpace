import heapq

pq = []
N = int(input())

for i in range(N):
  nums = list(map(int, input().split()))

  for n in nums:
    if len(pq) < N:
      heapq.heappush(pq, n)
    else:
      if pq[0] < n:
        heapq.heappop(pq)
        heapq.heappush(pq, n)

print(pq[0])