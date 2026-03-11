N = int(input())

isExist = [False]*26

for _ in range(N):
  words = list(input().split())
  flag = False
  result = []
  for word in words:
    idx = ord(word[0].lower()) - ord('a')
    if not isExist[idx] and not flag:
      isExist[idx] = True
      flag = True
      result.append('[' + word[0] + ']' + word[1:])
    else:
      result.append(word)

  if flag:
    print(' '.join(result))

  else:
    result = []
    for i in range(len(words)):
      word = words[i]
      if flag:
        result.append(word)
        continue
      for j in range(len(word)):
        idx = ord(word[j].lower()) - ord('a')
        if not isExist[idx] and not flag:
          flag = True
          isExist[idx] = True
          result.append(word[0:j] + '[' + word[j] + ']' + word[j+1:])
    
      if not flag:
        result.append(word)
    print(' '.join(result))