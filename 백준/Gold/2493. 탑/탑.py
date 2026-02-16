from collections import deque

N = int(input())
tops = list(map(int, input().split()))

S = list()
outs = [0]*N

tops.reverse()

S.append([tops[0], N-1])

num = N-1

for i in range(1, N):
  length = len(S)
  idx = len(S)-1
  for j in range(length):
    if S[idx][0] <= tops[i]:
      outs[S[idx][1]] = num
      S.pop()
      idx -= 1
    else: break
  S.append([tops[i], N-i-1])
  num -= 1


for i in outs:
  print(i, end = ' ')
