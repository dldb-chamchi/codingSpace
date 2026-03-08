N, L = map(int, input().split())

for i in range(L, 101):
  check = (N-i*(i-1)//2)
  if not check%i and check >= 0:
    check //= i
    for j in range(check, check+i):
      print(j, end=' ')
    exit()

print(-1)