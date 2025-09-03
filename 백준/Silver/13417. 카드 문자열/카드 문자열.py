#백준, 13417 카드 문자열

import sys
from collections import deque
input = sys.stdin.readline

for i in range(int(input())):
    d = deque()
    N = int(input())
    cards = list(input().split())
    d.append(cards[0])
    
    for i in range(1, N):
        if d[0] >= cards[i]:
            d.appendleft(cards[i])
        else:
            d.append(cards[i])
    print(*d, sep='')