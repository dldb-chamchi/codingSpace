N = int(input())

jobs = []

for i in range(N):
    T, S = map(int, input().split())
    jobs.append((T, S))

jobs.sort(key= lambda x : x[1], reverse=True)
time = jobs[0][1] - jobs[0][0]

for i in range(1, N):
    if time > jobs[i][1]:
        time = jobs[i][1] - jobs[i][0]
    else:
        time -= jobs[i][0]

print(time if time >= 0 else -1)