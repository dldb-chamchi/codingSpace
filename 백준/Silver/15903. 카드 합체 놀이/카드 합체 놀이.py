import heapq

N, M = map(int, input().split())

nums = list(map(int, input().split()))

heapq.heapify(nums)

for _ in range(M):
  x = heapq.heappop(nums)
  y = heapq.heappop(nums)
  heapq.heappush(nums, x+y)
  heapq.heappush(nums, x+y)

print(sum(nums))