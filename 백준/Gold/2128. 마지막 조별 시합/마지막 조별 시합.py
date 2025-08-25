#백준 2128, 마지막 조별 시합

import sys
input = sys.stdin.readline

N, D, K = map(int, input().rstrip().split())

inform = []
pickedProblems = []
answer = 0

for i in range(N):
    data = list(map(int, input().rstrip().split()))
    problems = data[1:]
    inform.append(set(problems))

def countStudents(setPicked):
    cnt = 0
    for s in inform:
        if s.issubset(setPicked):
            cnt += 1
    return cnt

def pickProblem(depth, start):
    global answer

    if depth == K:
        setPicked = set(pickedProblems)
        answer = max(answer, countStudents(setPicked))
        return

    if D - start + 1 < K - depth: 
        return

    for i in range(start, D+1):
        pickedProblems.append(i)
        pickProblem(depth+1, i+1)
        pickedProblems.pop()

pickProblem(0, 1)
print(answer)