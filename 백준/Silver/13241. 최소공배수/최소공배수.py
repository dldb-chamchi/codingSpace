A, B = map(int, input().split())
ab = A*B

while B > 0:
    if A > B:
        A, B = B, A
    B %= A

print((ab)//A)