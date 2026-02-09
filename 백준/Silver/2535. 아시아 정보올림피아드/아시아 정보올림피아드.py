N = int(input())

countries = [0]*N
students = []

for _ in range(N):
    c, n, s = map(int, input().split())
    students.append([s, c, n])

students.sort(reverse=True)

cnt = 0
for s, c, n in students:
    if cnt == 3:
        break
    if countries[c] < 2:
        countries[c] += 1
        print(c, n)
        cnt += 1