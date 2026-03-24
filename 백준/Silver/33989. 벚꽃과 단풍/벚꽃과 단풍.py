N = int(input())
S = input()

B = 0

for ch in S:
  if ch == 'B':
    B += 1

b, d = 0, 0
idx = 0

ans = B
for ch in S:
  if ch == 'D':
    d += 1
  else:
    b += 1
  ans = min(d + (B-b), ans)
  idx += 1

print(ans)