#백준 1049 기타줄
N, M = map(int, input().split())

#6개 묶음은 패키지 나머지는 낱개
#모두 패키지
#모두 낱개
#브랜드 섞이기 가능

minPakage = 99999
minOne = 99999
for i in range(M):
    pakage, one = map(int, input().split())
    minPakage = min(minPakage, pakage)
    minOne = min(minOne, one)

pakageN = N//6 if not N%6 else N//6 + 1

print(min(pakageN*minPakage, min(N//6 * minPakage + N%6 * minOne, minOne*N)))
