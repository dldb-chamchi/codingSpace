def palindrom(word):
  for i in range(len(word)//2):
    if word[i] != word[-i-1]:
      return False
  return True

def check():
  for i in range(K):
    for j in range(K):
      if i == j:
        continue
      if palindrom(words[i]+words[j]):
        return words[i]+words[j]

for _ in range(int(input())):
  words = []
  K = int(input())
  for _ in range(K):
    words.append(input())
  answer = check()
  print(0) if answer is None else print(answer)