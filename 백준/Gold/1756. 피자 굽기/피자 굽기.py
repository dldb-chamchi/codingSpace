#백준 1756, 피자

D, N = map(int, input().split())

depth = list(map(int, input().split()))
pizza = list(map(int, input().split()))

for i in range(D-1):
    if depth[i] < depth[i+1]:
        depth[i+1] = depth[i]

idx = 0
for i in range(D-1, -1, -1):
    if pizza[idx] <= depth[i]:
        idx += 1

    if idx == N:
        print(i+1) 
        break

else: print(0)