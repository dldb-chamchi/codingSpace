def solution(board, skill):
    
    n = len(board)
    m = len(board[0])

    update = [[0]*(m+1) for _ in range(n+1)]

    for type, r1, c1, r2, c2, degree in skill:
        if type == 1:
            update[r1][c1] -= degree
            update[r1][c2+1] += degree
            update[r2+1][c1] += degree
            update[r2+1][c2+1] -= degree
            
        elif type == 2:
            update[r1][c1] += degree
            update[r1][c2+1] -= degree
            update[r2+1][c1] -= degree
            update[r2+1][c2+1] += degree

    for i in range(n):
        for j in range(1, m):
            update[i][j] += update[i][j-1]
            
    for i in range(m):
        for j in range(1, n):
            update[j][i] += update[j-1][i]
    
    answer = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] + update[i][j] > 0:
                answer += 1
    
    return answer