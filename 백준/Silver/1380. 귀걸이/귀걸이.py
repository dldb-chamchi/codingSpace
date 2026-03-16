idx = 1

while True:
  N = int(input())
  if not N:
    break
  visit = [False]*(N+1)
  names = []
  for _ in range(N):
    names.append(input())
  
  for _ in range(2*N-1):
    n, alpah = input().split()
    n = int(n)
    if visit[n]:
      visit[n] = False
    else:
      visit[n] = True
  
  for i in range(1, N+1):
    if visit[i]:
      print(idx, names[i-1])
      break
  idx += 1