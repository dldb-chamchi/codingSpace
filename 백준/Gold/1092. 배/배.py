N = int(input())
crane = list(map(int, input().split()))

M = int(input())
box = list(map(int, input().split()))

crane.sort(reverse=True)
box.sort(reverse=True)

visit = [False]*M
pos = [0]*N


if crane[0] < box[0]:
  print(-1)
  exit()

m = 0
done = 0

while done < M:
  for i in range(N):
    for j in range(pos[i], M):
      pos[i] = j + 1
      if visit[j]:
        continue
      if crane[i] >= box[j]:
        visit[j] = True
        pos[i] = j+1
        done += 1
        break
        
  m += 1

print(m)