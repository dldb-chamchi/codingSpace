#백준, 5635 생일

N = int(input())

students = []

for i in range(N):
    name, d, m, y = input().split()
    students.append([int(y), int(m), int(d), name])

students.sort()

print(students[-1][3])
print(students[0][3])