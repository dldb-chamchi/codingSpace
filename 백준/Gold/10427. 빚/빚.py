import sys
input = sys.stdin.readline

for i in range(int(input().rstrip())):
    N, *light = map(int, input().split())

    light.sort()
    sumLight = [0]*(N+1)

    for i in range(N):
        sumLight[i+1] = sumLight[i] + light[i]

    ans = 0

    for i in range(2, len(light)+1):
        minCost = float('inf')
        for j in range(N-i+1):
            preSum = sumLight[j+i] - sumLight[j]
            maxNum = light[j+i-1]
            cost = maxNum * i - preSum
            minCost = min(cost, minCost)
        ans += minCost

    print(ans)

