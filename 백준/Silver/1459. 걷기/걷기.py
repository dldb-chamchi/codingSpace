X, Y, W, S = map(int, input().split())

INF = 10**30

if W*2 <= S:
  print((X+Y)*W)
else:
  answer = 0
  m = min(X, Y)
  answer += m*S #ex) 4, 0까지
  d = (X-m)+(Y-m) #abs(X-Y)

  case1, case2, case3 = INF, INF, INF
  if d % 2 == 0: #대각선 처리가 가능
    case1 = answer + d*S
  else:
    case2 = answer + (d-1)*S + W

  case3 = answer + d*W

  print(min(case1, case2, case3))
  