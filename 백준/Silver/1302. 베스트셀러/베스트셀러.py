N = int(input())

dic = {}

for _ in range(N):
  book = input()
  if book in dic:
    dic[book] += 1
  else:
    dic[book] = 1

maxCnt = max(dic.values())

answer = sorted([title for title, cnt in dic.items() if cnt == maxCnt])[0]
print(answer)