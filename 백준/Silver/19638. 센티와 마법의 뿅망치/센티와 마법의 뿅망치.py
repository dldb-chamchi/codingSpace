import heapq

N, H, T = map(int, input().split())

heights = []

for _ in range(N):
  h = int(input())
  heapq.heappush(heights, -h)

if -heights[0] < H:
  print("YES")
  print(0)
  exit()

for i in range(T):
  if -heights[0] >= H:
    h = -heapq.heappop(heights)
    if h > 1:
      h //= 2
    heapq.heappush(heights, -h)
  if -heights[0] < H:
    print("YES")
    print(i+1)
    exit()

print("NO")
print(-heapq.heappop(heights))