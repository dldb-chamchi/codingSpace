#백준 21921, 블로그

N, X = map(int, input().split())

visiter = list(map(int, input().split()))

maxSum = 0
ran = 1
for i in range(0, X):
    maxSum += visiter[i]

total = maxSum
for i in range(X, len(visiter)):
    total += visiter[i]
    total -= visiter[i-X]
    if total == maxSum:
        ran += 1
    elif total > maxSum:
        maxSum = total
        ran = 1

if maxSum == 0: 
    print("SAD")
    exit()
print(maxSum)
print(ran)
