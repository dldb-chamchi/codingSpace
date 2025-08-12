N = int(input())
nums = list(map(int, input().split()))
K = int(input())

st = 0; end = 0; cnt = 0; sums = 0

while st <= end:
    if sums > K:
        cnt += N - end + 1
        sums -= nums[st]
        st += 1
    elif end == N:
        break
    elif sums <= K:
        sums += nums[end]
        end += 1

print(cnt)