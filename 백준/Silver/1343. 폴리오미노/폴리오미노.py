#백준 1343, 폴리오미노

board = input()

result = []
idx = 0

while idx < len(board):
    if board[idx] == '.':
        result.append('.')
        idx += 1
    else:
        if idx + 4 <= len(board) and board[idx:idx+4] == "XXXX":
            result.append("AAAA")
            idx += 4
        elif idx + 2 <= len(board) and board[idx:idx+2] == "XX":
            result.append("BB")
            idx += 2
        else:
            print(-1)
            exit()

print(''.join(result))