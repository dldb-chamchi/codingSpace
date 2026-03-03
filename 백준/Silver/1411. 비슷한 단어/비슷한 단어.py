N = int(input())

count = {}
for _ in range(N):
  seq = 0
  pattern = []
  mapping = {}

  words = input()
  for w in words:
    if w not in mapping:
      mapping[w] = seq
      seq += 1
    pattern.append(mapping[w])
  
  p = tuple(pattern)
  if p in count:
    count[p] += 1
  else:
    count[p] = 1

ans = 0
for cnt in count.values():
  ans += cnt*(cnt-1)//2

print(ans)