#백준, 18429 근손실

N, K = map(int, input().split())

fiteness = list(map(int, input().split()))

caseSum = 0

visit = [False] * N

def back(depth, weight):
    global caseSum
    if depth == N:
        caseSum += 1
        return

    for i in range(N):
        if not visit[i]:
            stand = weight+fiteness[i]-K
            if  stand >= 500:
                visit[i] = True
                back(depth+1, stand)
                visit[i] = False

back(0, 500)

print(caseSum)


