#백준, 1063 킹

king, stone, N = input().split()

rule = {'R':(0, 1),
        "L":(0, -1),
        "B":(-1, 0),
        "T":(1, 0),
        "RT":(1, 1),
        "LT":(1, -1),
        "RB":(-1, 1),
        "LB":(-1, -1)}

board = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']

k1, k2 = int(king[1])-1, board.index(king[0])
s1, s2 = int(stone[1])-1, board.index(stone[0])

for _ in range(int(N)):
    x, y = rule[input()]
    
    if 0 <= k1 + x < 8 and 0 <= k2 + y < 8:
        k1, k2 = k1 + x, k2 + y
        if k1 == s1 and k2 == s2:
            s1, s2 = s1+x, s2+y

    if s1 < 0 or s1 >= 8 or s2 < 0 or s2 >= 8:
        k1, k2 = k1-x, k2-y
        s1, s2 = s1-x, s2-y

print(board[k2] + str(k1+1))
print(board[s2] + str(s1+1))