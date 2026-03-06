N, M = map(int, input().split())

train = [[False]*20 for _ in range(N)]
for _ in range(M):
  cmd = list(map(int, input().split()))
  if cmd[0] == 1:
    train[cmd[1]-1][cmd[2]-1] = True
  elif cmd[0] == 2:
    train[cmd[1]-1][cmd[2]-1] = False
  elif cmd[0] == 3:
    for j in range(19, 0, -1):
      train[cmd[1]-1][j] = train[cmd[1]-1][j-1]
    train[cmd[1]-1][0] = False
  elif cmd[0] == 4:
    for j in range(19):
      train[cmd[1]-1][j] = train[cmd[1]-1][j+1]
    train[cmd[1]-1][19] = False

s = set()
for t in train:
  s.add(tuple(t))
print(len(s))