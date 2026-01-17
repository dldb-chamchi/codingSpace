def check():
    global result
    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if board[i][j] == board[i][j+1]:
                cnt += 1
                result = max(result, cnt)
            else: cnt = 1

    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if board[j][i] == board[j+1][i]:
                cnt += 1
                result = max(result, cnt)
            else: cnt = 1

result = 1

N = int(input())

board = [list(input()) for _ in range(N)]

for i in range(N):
    for j in range(N-1):
        board[i][j], board[i][j+1] = board[i][j+1], board[i][j] #행
        check()
        board[i][j+1], board[i][j] = board[i][j], board[i][j+1]

        board[j][i], board[j+1][i] = board[j+1][i], board[j][i] #열
        check()
        board[j+1][i], board[j][i] = board[j][i], board[j+1][i]

print(result)
