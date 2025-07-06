import sys
input = sys.stdin.readline

bingo = [list(map(int, input().rstrip().split())) for _ in range(5)]



def solve(num):
    bingoCnt = 0
    for i in range(5):
        for j in range(5):
            if bingo[i][j] == num:
                bingo[i][j] = 0
    

    for i in range(5):
        if len(set(bingo[i])) == 1:
            bingoCnt += 1
        
    for i in range(5):
        col = [row[i] for row in bingo]
        if len(set(col)) == 1:
            bingoCnt += 1
    
    if all(bingo[i][i] == 0 for i in range(5)):
        bingoCnt += 1

    if all(bingo[i][5-1-i] == 0 for i in range(5)):
        bingoCnt += 1

    return bingoCnt
s = 0
nums = []
for i in range(5):
    nums.append(list(map(int, input().rstrip().split())))

for i in range(5):
    for j in range(5):
        if solve(nums[i][j]) >= 3:
            print(s+1+j)
            exit()
    s += 5
    

