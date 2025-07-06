#백준 33807, 빗질의 중요성

N, M = map(int, input().split())

dogs = list(map(int, input().split()))

days = list(map(int, input().split()))

combs = [[] for _ in range(N)]
for d, dog in enumerate(days, start=1):
    combs[dog-1].append(d)

status = [0] * N   #0 풀림, 1 엉킴

ans = 0

for i in range(N):
    k = dogs[i] #강아지 엉킴 일수
    last = 0 #마지막 날
    con = 0 #엉킴 풀기 확인
    state = 0

    for d in combs[i]:
        if state == 0 and d - last - 1 >= k:
            state = 1
            con = 0

        if state == 1 and con == 1 and d == last + 1: #엉킴 연속 빗질 풀기
            state = 0

        con = 1 if state == 1 else 0

        last = d #마지막 일수 업뎃

    if state == 0 and (M - last) >= k : state = 1 #M+1 계산

    if state == 1: ans += 1

print(ans)
