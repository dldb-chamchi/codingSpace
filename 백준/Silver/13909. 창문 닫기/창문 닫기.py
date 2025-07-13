N = int(input())

ans = 0
x = 1
while x**2 <= N:
    x += 1
    ans += 1

print(ans)