def recur(a, b, n):
    if n == 1:
        print(f"{a} {b}")
        return

    recur(a, 6-a-b, n-1)
    print(f"{a} {b}")
    recur(6-a-b, b, n-1)

N = int(input())

print((1 << N)-1)
recur(1, 3, N)
