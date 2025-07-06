import sys
input = sys.stdin.readline

N, M, K = map(int, input().rstrip().split())

rainSum = 0
rain = []
for _ in range(M):
    rain.append(list(map(int, input().rstrip().split())))
    
for i in range(M):
    rainSum += rain[i][1]
    if rainSum > K:
        print(i+1, 1)
        exit()

print(-1)

