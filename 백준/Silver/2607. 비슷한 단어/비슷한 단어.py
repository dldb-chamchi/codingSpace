N = int(input())

std = input()
freqStd = [0]*26
cnt = 0

for c in std:
    freqStd[ord(c)-ord('A')] += 1

for i in range(N-1):
    freq = [0]*26
    compare = input()

    for c in compare:
        freq[ord(c)-ord('A')] += 1

    add = minus = 0

    for j in range(26):
        d = freqStd[j] - freq[j]
        if d > 0:
            add += d
        elif d < 0:
            minus += -d

    diff = add + minus

    if diff == 0 or diff == 1 or (diff == 2 and add == 1 and minus == 1):
        cnt += 1

print(cnt)