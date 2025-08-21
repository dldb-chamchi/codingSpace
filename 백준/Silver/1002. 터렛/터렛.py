#백준, 1002 터렛

import sys
import math
input = sys.stdin.readline

for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    distance = math.sqrt((x1-x2)**2 + (y1-y2)**2)
    
    d1 = abs(r1 - r2)
    d2 = r1 + r2

    if distance == 0 and r1 == r2:
        print(-1)
    elif distance == d1 or distance == d2:
        print(1)
    elif d1 < distance < d2:
        print(2)
    else:
        print(0)