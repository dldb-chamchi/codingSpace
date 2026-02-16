import sys

input = sys.stdin.readline



for _ in range(int(input())):
  clothes = dict()
  N = int(input())
  for i in range(N):
    name, types = input().split()
    if types in clothes:
      clothes[types] += 1
    else:
      clothes[types] = 1


  ans = 1
  for value in clothes.values():
    tmp = value+1
    ans *= tmp

  print(ans-1)