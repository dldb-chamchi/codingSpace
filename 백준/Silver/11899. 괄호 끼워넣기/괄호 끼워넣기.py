#백준, 11899 괄호 끼워넣기

from collections import deque

string = input()

d = deque()

cnt = 0
for c in string:
    if c == '(':
        d.append('(')
    else:
        if d:
            d.pop()
        else:
            cnt += 1

cnt += len(d)

print(cnt)