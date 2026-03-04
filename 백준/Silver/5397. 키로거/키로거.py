from collections import deque

T = int(input())

for _ in range(T):
  L = deque()
  R = deque()

  keyloger = input()

  for ch in keyloger:
    if ch == '<' and L:
      R.appendleft(L.pop())
    elif ch == '>' and R:
      L.append(R.popleft())
    elif ch == '-' and L:
      L.pop()
    elif ch != '<' and ch!= '>' and ch != '-':
      L.append(ch)

  for ch in L:
    print(ch, end='')
  for ch in R:
    print(ch, end='')
  print()