from collections import deque

idx = 0
while True:
  idx += 1
  string = input()
  if '-' in string:
    break

  cnt = 0
  Q = deque()
  for ch in string:
    if ch == '}' and Q:
      if Q[len(Q)-1] == '{':
        Q.pop()
    elif ch == '{':
      Q.append('{')
    else:
      cnt += 1
      Q.append('{')
  
  cnt += len(Q)//2
  print(f"{idx}.", cnt)