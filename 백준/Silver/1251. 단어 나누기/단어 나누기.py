word = input()

result = []
for i in range(1, len(word)):
  for j in range(i+1, len(word)):
    one = word[:i][::-1]
    two = word[i:j][::-1]
    three = word[j:][::-1]
    result.append(one + two + three)

result.sort()
print(result[0])