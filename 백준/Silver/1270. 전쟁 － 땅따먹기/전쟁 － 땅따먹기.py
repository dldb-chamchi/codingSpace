N = int(input())

for _ in range(N):
  dic = {}
  li = list(map(int, input().split()))
  n = li[0]
  li[0], li[n] = li[n], li[0]
  li.pop()

  for i in li:
    if i in dic:
      dic[i] += 1
    else:
      dic[i] = 1
  
  flag = 0
  num = 0

  for number, cnt in dic.items():
    if cnt > n//2:
      if not flag:
        flag = 1
        num = number
      elif flag == 1:
        flag = 2


  if flag == 2 or not flag:
    print("SYJKGW")
  else:
    print(num)
  