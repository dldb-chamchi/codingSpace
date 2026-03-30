N = int(input())

lines = []
for _ in range(N):
  lines.append(list(map(int, input().split())))

lines.sort()

sums = 0
l, r = lines[0][0], lines[0][1]
for i in range(1, N):
  if lines[i][0] > r: #안겹침
    sums += r-l
    l, r = lines[i][0], lines[i][1]
  else:
    r = max(lines[i][1], r)

sums += r-l
print(sums)