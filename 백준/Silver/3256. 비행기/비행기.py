N = int(input())

passengers = []

for _ in range(N):
  passengers.append(int(input()))

passengers.reverse()

L = max(passengers)

check = [None]*(L+1)

time = 0
while passengers or any(check[1:]):
  if check[1] is None and passengers:
    check[1] = [passengers.pop(), -1]
  
  for i in range(L, 0, -1):
    if check[i] is not None:
      if check[i][0] == i:
        if check[i][1] == -1:
          check[i][1] = 5
        check[i][1] -= 1
        if check[i][1] == 0:
          check[i] = None
      else:
        if i < L and check[i+1] is None:
          check[i+1] = check[i]
          check[i] = None
  time += 1

print(time)

