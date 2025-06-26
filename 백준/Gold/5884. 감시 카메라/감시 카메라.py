N = int(input())

points = [tuple(map(int, input().split())) for _ in range(N)]

xIdx = {}; yIdx = {}
xcount = []; ycount = []

idx = 0
for x, _ in points:
    if x not in xIdx:
        xIdx[x] = idx
        xcount.append(0)
        idx += 1
    xcount[xIdx[x]] += 1

idy = 0

for _, y in points:
    if y not in yIdx:
        yIdx[y] = idy
        ycount.append(0)
        idy += 1
    ycount[yIdx[y]] += 1

if idx <= 3 or idy <= 3:
    print(1)
    exit()
    
xList = [[] for _ in range(idx)]
yList = [[] for _ in range(idy)]

for x, y in points:
    xi = xIdx[x]
    yi = yIdx[y]
    xList[xi].append(yi)
    yList[yi].append(xi)

for xi in range(idx):
    cnt = sum(1 for yi in xList[xi] if ycount[yi] == 1)
    if idy - cnt <= 2:
        print(1)
        exit()

for yi in range(idy):
    cnt = sum(1 for xi in yList[yi] if xcount[xi] == 1)
    if idx - cnt <= 2:
        print(1)
        exit()

print(0)