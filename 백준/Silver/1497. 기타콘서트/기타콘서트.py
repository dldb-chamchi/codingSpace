def back(depth, n, start, visit):
    global ans, maxSong
    
    if depth == n:
        currBit = 0
        for i in range(N):
            if visit[i]:
                currBit |= check[i]

        cnt = bin(currBit).count('1')
        
        if cnt > maxSong:
            maxSong = cnt
            ans = n
        return

    for i in range(start, N):
        if visit[i]:
            continue
        visit[i] = True
        back(depth+1, n, i+1, visit)
        visit[i] = False

N, M = map(int, input().split())

check = [0] * N

for i in range(N):
    guitar, ava = input().split()
    
    bit = 0
    for j in range(M):
        if ava[j] == 'Y':
            bit |= (1 << (M - 1 - j))
    check[i] = bit

ans = -1
maxSong = 0
for i in range(1, N + 1):
    visit = [False]*N
    back(0, i, 0, visit)
    if maxSong == M:
        break

print(ans if maxSong > 0 else -1)