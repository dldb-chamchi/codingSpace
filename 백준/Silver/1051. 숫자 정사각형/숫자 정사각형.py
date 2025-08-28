import sys
input = sys.stdin.readline

N, M = map(int, input().split())
numbers = [input().strip() for _ in range(N)]

maxArea = 1

for k in range(N):
    for i in range(M):
        for j in range(i+1, M):
            s = j-i
            if k+s < N:
                num = numbers[k][i]
                if num == numbers[k][j] == numbers[k+s][i] == numbers[k+s][j]:
                    side = s + 1
                    maxArea = max(maxArea, side * side)

print(maxArea)
