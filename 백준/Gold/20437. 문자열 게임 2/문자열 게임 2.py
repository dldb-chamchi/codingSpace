for _ in range(int(input())):
  string = input()
  K = int(input())

  dic = {}

  idx = 0
  for s in string:
    if s in dic:
      dic[s].append(idx)
    else:
      dic[s] = [idx]
    idx += 1

  maxs, mins = 0, 9999999
  for value in dic.values():
    if len(value) < K:
      continue
    for i in range(len(value)-K+1):
      maxs = max(maxs, value[i+K-1]-value[i]+1)
      mins = min(mins, value[i+K-1]-value[i]+1)

  print(-1 if maxs == 0 else f"{mins} {maxs}")