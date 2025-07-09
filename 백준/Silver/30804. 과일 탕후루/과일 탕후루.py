import sys
input = sys.stdin.readline

N = int(input().rstrip())

fruit = list(map(int, input().rstrip().split()))

j = 0
diffFruit = {}
maxL = 0
for i in range(len(fruit)):
    if fruit[i] in diffFruit:
        diffFruit[fruit[i]] += 1
    else:
        diffFruit[fruit[i]] = 1
    
    while len(diffFruit) > 2:
        diffFruit[fruit[j]] -= 1
        if diffFruit[fruit[j]] == 0:
            del diffFruit[fruit[j]]
        j += 1

    maxL = max(maxL, i-j+1)

print(maxL)