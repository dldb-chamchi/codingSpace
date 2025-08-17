# 백준 1895, 필터

def threeBy(x, y):
    nums = []
    for i in range(x, x+3):
        for j in range(y, y+3):
            nums.append(grid[i][j])
    
    nums.sort()
    return 1 if nums[4] >= T else 0


R, C = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(R)]

T = int(input())

cnt = 0

for i in range(R-2):
    for j in range(C-2):
        cnt += threeBy(i, j)

print(cnt)