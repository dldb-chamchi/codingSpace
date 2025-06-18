
nums = []
for i in range(int(input())):
    sum = 0
    li = list(map(int, input().split()))

    for i in range(1, len(li)):
        sum += li[i]
    nums.append(sum)
    

nums.sort()
total = 0
ans = 0

for i in nums:
    total += i
    ans += total

print(ans)
