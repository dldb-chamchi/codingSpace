W, H = map(int, input().split())

width = [0, W]
height = [0, H]

for i in range(int(input())):
    op, num = map(int, input().split())

    if op == 0:
        height.append(num)
    else:
        width.append(num)

height.sort()
width.sort()

area = 0
for i in range(len(width)-1):
    for j in range(len(height)-1):
        x = width[i+1] - width[i]
        y = height[j+1] - height[j]
        area = max(area, x*y)

print(area)
        