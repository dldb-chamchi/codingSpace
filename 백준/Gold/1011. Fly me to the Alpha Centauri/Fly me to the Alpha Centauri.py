import math

for _ in range(int(input())):
  x, y = map(int, input().split())
  dist = y-x

  n = math.isqrt(dist)

  if dist == n*n:
    print(2*n-1)
  elif dist <= n*n+n:
    print(2*n)
  else:
    print(2*n+1)