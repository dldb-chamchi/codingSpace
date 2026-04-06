string = input()

cnt = 0
for _ in range(int(input())):
  comp = input()
  comp += comp[:-1]

  for i in range(len(comp)):
    if comp[i:].startswith(string):
      cnt += 1
      break

print(cnt)