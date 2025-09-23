N = int(input())
seq = list(map(int, input().split()))
nums = [0]*N

for i in range(N):
    zero = seq[i]
    idx = 0
    while idx < N:
        if nums[idx] == 0:
            if zero == 0:
                nums[idx] = i + 1
                break
            zero -= 1
        idx += 1

print(*nums)
