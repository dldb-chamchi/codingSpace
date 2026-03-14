N = int(input())

students = [list(map(int, input().split())) for _ in range(N)]

ans = -1
student = 0
for k in range(N):
  visit = [False]*N
  for i in range(5):
    val = students[k][i]
    for j in range(N):
      if k == j:
        continue
      if students[j][i] == val:
        visit[j] = True

  cnt = sum(visit)
  if cnt > ans:
    ans = cnt
    student = k

print(student + 1)