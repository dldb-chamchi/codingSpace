import sys
input = sys.stdin.readline


for i in range(int(input())):
    stX, stY, edX, edY = map(int, input().split())

    N = int(input())

    cnt = 0
    for i in range(N):
        x, y, r = map(int, input().split())
        d1 = (stX-x) ** 2 + (stY-y) ** 2
        d2 = (edX-x) ** 2 + (edY-y) ** 2
        if (d1 < r**2 and d2 > r**2) or (d1 > r**2 and d2 < r**2):
            cnt += 1

    print(cnt) 