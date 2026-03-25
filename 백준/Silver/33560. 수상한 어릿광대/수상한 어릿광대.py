def gift(score):
  global one, two, three, four
  if 35 <= score < 65:
    one += 1
  elif 65 <= score < 95:
    two += 1
  elif 95 <= score < 125:
    three += 1
  elif score >= 125:
    four += 1

N = int(input())
dice = list(map(int, input().split()))

time, score = 0, 0
addTime, addScore = 4, 1
one, two, three, four = 0, 0, 0, 0

def end():
  global time, score, addTime, addScore

  time = 0
  gift(score)
  score = 0
  addTime = 4
  addScore = 1

for d in dice:
  if d == 1:
    end()
    continue
  elif d == 2:
    if addScore > 1:
      addScore //= 2
    else:
      addTime += 2
  elif d == 4:
    time += 56
  elif d == 5:
    if addTime > 1:
      addTime -= 1
  elif d == 6:
    if addScore < 32:
      addScore *= 2

  time += addTime
  score += addScore

  if time > 240:
    end()

print(one)
print(two)
print(three)
print(four)