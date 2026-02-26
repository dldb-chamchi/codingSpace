import sys
input = sys.stdin.readline

N, M = map(int, input().split())

keyword = {}

for _ in range(N):
  keyword[input().strip()] = True


for _ in range(M):
  write = input().strip().split(',')
  for word in write:
    keyword.pop(word, None)

  print(len(keyword))