N = int(input())

straw = [int(input()) for _ in range(N)]

straw.sort(reverse=True)

maxLen = 0
for i in range(N-2):
    maxVal = straw[i]
    compVal = straw[i+1]+straw[i+2]
    if maxVal < compVal:
        maxLen = max(maxLen, maxVal+compVal)

print(-1 if maxLen == 0 else maxLen)
