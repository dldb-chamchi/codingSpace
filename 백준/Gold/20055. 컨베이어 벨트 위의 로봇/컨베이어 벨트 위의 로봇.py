N, K = map(int, input().split())

box = list(map(int, input().split()))

upBox = [0]*N
downBox = [0]*N
for i in range(N):
  upBox[i] = [box[i], False]

for i in range(N):
  downBox[i] = [box[N+i], False]

time= 0
while True:
  time += 1

  if upBox[N-1][1]: #끝에 로봇 내리기
    upBox[N-1][1] = False
  
  upLast = upBox[N-1][0]

  for i in range(N-1, 0, -1): #위쪽 돌리기
    upBox[i][1] = upBox[i-1][1]
    upBox[i][0] = upBox[i-1][0]
  
  if upBox[N-1][1]: #끝에 로봇 내리기
    upBox[N-1][1] = False
  
  downLast = downBox[N-1][0]

  for i in range(N-1, 0, -1): #아래쪽 돌리기
    downBox[i][0] = downBox[i-1][0]

  upBox[0][0] = downLast
  downBox[0][0] = upLast
  upBox[0][1] = False

  for i in range(N-1, 0, -1): #위쪽 돌리기
    if not upBox[i][1] and upBox[i-1][1] and upBox[i][0] != 0:
      upBox[i-1][1] = False
      upBox[i][1] = True
      upBox[i][0] -= 1

  if upBox[0][0] != 0 and not upBox[0][1]: #박스 올리기
    upBox[0][1] = True
    upBox[0][0] -= 1
  
  if upBox[N-1][1]: #끝에 로봇 내리기
    upBox[N-1][1] = False
  
  k = 0
  for i in range(N):
    if upBox[i][0] == 0:
      k += 1
    if downBox[i][0] == 0:
      k+=1
  if k >= K:
    break

print(time)