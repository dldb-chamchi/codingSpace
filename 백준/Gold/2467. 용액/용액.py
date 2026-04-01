N = int(input())

nums = list(map(int, input().split()))

l, r = 0, N-1

ans = float('inf')
a, b = 0, 0

while l < r:
  sums = nums[l]+nums[r]
  if abs(sums) < ans:
    ans = abs(sums)
    a, b = l, r
  
  if sums == 0: break
  elif sums > 0: r -= 1
  else: l += 1

print(nums[a], nums[b])