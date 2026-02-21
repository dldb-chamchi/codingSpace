N = int(input())

nums = [0] + list(map(int, input().split()))

dp = [0]*(N+1)

if N == 1:
  print(0)
  exit()
dp[2] = (nums[1] ^ nums[2]).bit_count()

if N == 2:
  print(dp[2])
  exit()

dp[3] = (nums[1] ^ nums[2] ^ nums[3]).bit_count()
if N == 3:
  print(dp[3])
  exit()

dp[4] = dp[2] + (nums[3] ^ nums[4]).bit_count()
if N == 4:
  print(dp[4])
  exit()

for i in range(5, N+1):
  dp[i] = max(dp[i-2] + (nums[i] ^ nums[i-1]).bit_count(),
              dp[i-3] + (nums[i] ^ nums[i-1] ^ nums[i-2]).bit_count())

print(0 if N == 1 else dp[N])