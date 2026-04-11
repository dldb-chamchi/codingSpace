N, game = input().split()
N = int(N)

if game == 'Y':
  member = 1
elif game == 'F':
  member = 2
else:
  member = 3

names = {}
cnt = 0
ans = 0
for i in range(N):
  name = input()
  if name not in names:
    cnt += 1
    names[name] = 1
  if cnt == member:
    ans += 1
    cnt = 0

print(ans)