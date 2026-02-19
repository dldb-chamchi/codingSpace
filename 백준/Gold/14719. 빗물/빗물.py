H, W = map(int, input().split())
blocks = list(map(int, input().split()))

cnt = 0

for i in range(1, W-1):
  left = 0; right = 0
  for j in range(0, i):
    left = max(left, blocks[j])
  for j in range(W-1, i, -1):
    right = max(right, blocks[j])
  
  cnt += max(0, min(left, right)-blocks[i])

print(cnt)