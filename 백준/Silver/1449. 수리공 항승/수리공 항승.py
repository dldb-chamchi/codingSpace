#백준, 1449 수리공 항승

N, L = map(int, input().split())

nums = list(map(int, input().split()))
nums.sort()

left, right = 0, 1
cnt = 1
while right < N:
    if nums[right] - nums[left] < L:
        right += 1
    else:
        cnt += 1
        left = right
        right += 1

print(cnt)