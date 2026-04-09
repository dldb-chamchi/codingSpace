for _ in range(int(input())):
  N = int(input())
  nums = list(map(int, input().split()))
  sums = [0]*N; sums[0] = nums[0]; s = nums[0]

  for i in range(1, N):
    s += nums[i]
    sums[i] = s
  
  ans = max(sums)

  for i in range(N-1, 0, -1):
    for j in range(i):
      ans = max(ans, sums[i]-sums[j])
  
  print(ans)