#백준, 7983 내일 할거야

import sys

N = int(input())

schedule = []

for i in range(N):
    open, close = map(int, sys.stdin.readline().rstrip().split())
    schedule.append([close, open])

schedule.sort(reverse=True)

day = schedule[0][0]

for close, open in schedule:
    if day >= close:
        day = close - open
    else:
        day -= open

print(day)
