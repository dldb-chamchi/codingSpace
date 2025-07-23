#백준, 1475 방 번호

num = input()
count = [False]*10

cnt = 0
maxV = 0
for i in num:
    count[int(i)] += 1

for i in range(10):
    if i == 6 or i == 9:
        continue
    else:
        maxV = max(count[i], maxV)

sixNine = (count[6] + count[9]) // 2 + 1 if (count[6] + count[9]) % 2 != 0 else  (count[6] + count[9]) // 2
maxV = max(maxV, sixNine)

print(maxV)