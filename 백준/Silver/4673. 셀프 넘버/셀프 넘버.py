def make(num):
  sums = num
  for n in str(num):
    sums += int(n) 

  return sums

visit = [False]*(50000)

for i in range(1, 10001):
  visit[make(i)] = True

for i in range(1, 10001):
  if not visit[i]:
    print(i)