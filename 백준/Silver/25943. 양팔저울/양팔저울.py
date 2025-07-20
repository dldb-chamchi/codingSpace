N = int(input())

gravel = list(map(int, input().split()))
weight = [100, 50, 20, 10, 5, 2, 1]

left = gravel[0]; right = gravel[1]
for i in range(2, N):
    if left > right:
        right += gravel[i]
    else:
        left += gravel[i]

diff = abs(left - right)

cnt = 0
for i in weight:
    cnt += diff//i
    diff %= i

print(cnt)
