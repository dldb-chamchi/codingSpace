#백준, 1205 등수 구하기

N, score, P = map(int, input().split())

if N > 0:
    rankings = list(map(int, input().split()))
else:
    rankings = []

rankings.sort(reverse=True)

if len(rankings) == P and rankings[-1] >= score:
        print(-1)
        exit()

nowRank = 1
for i in range(len(rankings)):
    if score >= rankings[i]:
        print(nowRank)
        exit()
    else:
        nowRank = i+2

print(nowRank)