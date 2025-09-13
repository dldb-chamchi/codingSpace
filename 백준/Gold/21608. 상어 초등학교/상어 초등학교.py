#백준, 21608 상어 초등학교

import sys
input = sys.stdin.readline

N = int(input())

grid = [[0] * N for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def search(student, likes):

    maxStuCnt, maxBlaCnt = -1, -1
    lastX, lastY = 0, 0
    for i in range(N):
        for j in range(N):
            if grid[i][j] != 0:
                continue

            x, y = searchLike(i, j, likes)
            if (x > maxStuCnt) or (x == maxStuCnt and (y > maxBlaCnt or (y == maxBlaCnt and (i < lastX or (i == lastX and j < lastY))))):
                maxStuCnt = x
                maxBlaCnt = y
                lastX, lastY = i, j
    grid[lastX][lastY] = student

def searchLike(x, y, likes):

    studentCnt = 0
    blankCnt = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < N and 0 <= ny < N:
            if grid[nx][ny] == 0:
                blankCnt += 1
            else:
                for s in likes:
                    if s == grid[nx][ny]:
                        studentCnt += 1
                        break

    return studentCnt, blankCnt

likeList = []

def likeCalc():
    maxVal = 0

    for s in likeList:
        stu, li = s[0], s[1:]
        for i in range(N):
            for j in range(N):
                if grid[i][j] == stu:
                    cnt = 0
                    for k in range(4):
                        nx = i + dx[k]
                        ny = j + dy[k]
                        if nx < 0 or ny < 0 or nx >= N or ny >= N:
                            continue
                        for l in li:
                            if l == grid[nx][ny]:
                                cnt += 1
                                break
                    if cnt == 1:
                        maxVal += 1
                    elif cnt == 2:
                        maxVal += 10
                    elif cnt == 3:
                        maxVal += 100
                    elif cnt == 4:
                        maxVal += 1000
    return maxVal

for i in range(N**2):
    like = list(map(int, input().split()))
    likeList.append(like)

    student, likes = like[0], like[1:]

    search(student, likes)

print(likeCalc())
