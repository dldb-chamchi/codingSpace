scores = {}

for i in range(1, 9):
    score = int(input())
    scores[score] = i

scores = sorted(scores.items(), key = lambda item: item[0], reverse = True)
scores = scores[:5]

numbers = []
sums = 0
for score, number in scores:
    sums += score
    numbers.append(number)

numbers.sort()
print(sums)
for i in numbers:
    print(i, end=' ')
