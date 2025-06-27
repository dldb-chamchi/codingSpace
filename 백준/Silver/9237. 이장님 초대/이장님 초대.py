N = int(input())

trees = list(map(int, input().split()))

trees.sort(reverse=True)

days = 2
for i in range(N):
    trees[i] += days
    days += 1

print(max(trees))