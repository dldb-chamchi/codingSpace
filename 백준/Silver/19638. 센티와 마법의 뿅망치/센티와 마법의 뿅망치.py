import heapq

N, H, T = map(int, input().split())

heights = []

for _ in range(N):
  h = int(input())
  heapq.heappush(heights, -h)

h = heapq.heappop(heights)
if -h < H:
  print("YES")
  print(0)
  exit()
else:
  heapq.heappush(heights, h)

for i in range(T):
  big = -heapq.heappop(heights)
  if big != 1:
    big //= 2
  heapq.heappush(heights, -big)
  nextBig = -heapq.heappop(heights)
  if nextBig < H:
    print("YES")
    print(i+1)
    exit()
  heapq.heappush(heights, -nextBig)

print("NO")
print(-heapq.heappop(heights))