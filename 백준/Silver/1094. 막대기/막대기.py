X = int(input())

cnt = 0
while X>0:
    if X % 2:
        cnt += 1
    X //= 2

print(cnt)